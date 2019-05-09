----------------------------------------------------------------------
-- Fichero: MicroMIPS.vhd
-- Autores: Irene Crusi Mozota y Laura Espada Caja
-- Grupo de Prácticas: 2122
-- Práctica: 4
----------------------------------------------------------------------


library IEEE;
use IEEE.std_logic_1164.ALL;
use IEEE.std_LOGIC_arith.ALL;
use IEEE.std_logic_unsigned.ALL;

entity MicroMIPS is
	port (
		Clk : in std_logic; -- Reloj
		NRst : in std_logic; -- Reset activo a nivel bajo
		MemProgAddr : out std_logic_vector(31 downto 0); -- Dirección para la memoria de programa
		MemProgData : in std_logic_vector(31 downto 0); -- Código de operación
		MemDataAddr : out std_logic_vector(31 downto 0); -- Dirección para la memoria de datos
		MemDataDataRead : in std_logic_vector(31 downto 0); -- Dato a leer en la memoria de datos
		MemDataDataWrite : out std_logic_vector(31 downto 0); -- Dato a guardar en la memoria de datos
		MemDataWE : out std_logic
	);
	end MicroMIPS;

architecture Practica of MicroMIPS is

	component ALUMIPS is
	port (
		Op1 : in std_logic_vector (31 downto 0);
		Op2 : in std_logic_vector (31 downto 0);
		ALUControl : in std_logic_vector (2 downto 0);
		Res : out std_logic_vector (31 downto 0);
		Z : out std_logic
	);
	end component;

	component RegsMIPS is
	port (
		Clk : in std_logic; -- Reloj
		NRst : in std_logic; -- Reset asíncrono a nivel bajo
		A1 : in std_logic_vector(4 downto 0); -- Dirección para el puerto Rd1
		Rd1 : out std_logic_vector(31 downto 0); -- Dato del puerto Rd1
		A2 : in std_logic_vector(4 downto 0); -- Dirección para el puerto Rd2
		Rd2 : out std_logic_vector(31 downto 0); -- Dato del puerto Rd2
		A3 : in std_logic_vector(4 downto 0); -- Dirección para el puerto Wd3
		Wd3 : in std_logic_vector(31 downto 0); -- Dato de entrada Wd3
		We3 : std_logic -- Habilitación del banco de registros
	); -- Salida RS
	end component;
	
	component UnidadControl is
	port (
		OPCode : in  std_logic_vector (5 downto 0); -- OPCode de la instrucción;
		Funct : in std_logic_vector(5 downto 0); -- Funct de la instrucción
		-- Señales para el PC
		Jump : out  std_logic;
		Branch : out  std_logic;
		PCToReg : out std_logic;
		
		-- Señales para la memoria
		MemToReg : out  std_logic;
		MemWrite : out  std_logic;

		RegDest : out  std_logic;
		-- Señales para la ALU
		ALUSrc : out  std_logic;
		ALUControl : out  std_logic_vector (2 downto 0);
		ExtCero : out std_logic;
		
		-- Señales para el GPR
		RegWrite : out  std_logic
	);
	end component;
	


	signal aluA, aluB, aluC : std_logic_vector(31 downto 0);

	signal regA3, sA3 : std_logic_vector(4 downto 0); -- Direcciones del GPR
	signal rd2, wd3 : std_logic_vector(31 downto 0); -- Registros GPR

	
	signal signExt, ceroExt, inmExt : std_logic_vector(31 downto 0); -- Dato inmediato extendido en signo
	signal instr : std_logic_vector(31 downto 0);
	signal extSignInmAux : std_logic_vector(15 downto 0);

	signal pc, pcBranch, pcMas4, pcIn, pcInPre, muxMTR : std_logic_vector(31 downto 0);
	
	signal aluControl : std_logic_vector(2 downto 0);

	signal flagZ : std_logic; -- Flag Z de la ALU
	
	signal jump, branch, memToReg, memWrite, regDest, aluSrc, regWrite, pcSrc, ExtCero, pctoreg : std_logic;
	

begin

	instr <= MemProgData; -- Alias para la instrucción
	
	InstALU: ALUMIPS 
	port map(
		Op1 => aluA,
		Op2 => aluB,
		ALUControl => aluControl,
		Res => aluC,
		Z => flagZ
	);

	InstRegs: RegsMIPS 
	port map(
		Clk => Clk,
		NRst => NRst,
		A1 => instr(25 downto 21),
		Rd1 => aluA,
		A2 => instr(20 downto 16),
		Rd2 => rd2,
		A3 => sA3,
		Wd3 => wd3,
		We3 => regWrite
	);
	
	
	regA3 <= instr(20 downto 16) when regDest = '0' else instr(15 downto 11); -- La dirección de escritura en GPR depende de si la insutrcción es R-type o no (regDest)
	
	InstUC: UnidadControl
	port map(
		OPCode => instr(31 downto 26), -- OPCode de la instrucción
		Funct => instr(5 downto 0), -- Funct de la instrucción
		-- Señales para el PC
		Jump => jump,
		Branch => branch,
		PCToReg => pctoreg,
		
		-- Señales para la memoria
		MemToReg => memToReg,
		MemWrite => memWrite,

		RegDest => regDest,
		-- Señales para la ALU
		ALUSrc => aluSrc,
		ALUControl => aluControl,
		ExtCero => extCero,

		-- Señales para el GPR
		RegWrite => regWrite
	);
		
		

		
	extSignInmAux <= (others => instr(15)); -- Extensión de signo
	signExt <= extSignInmAux & instr(15 downto 0); -- Extensión de signo
	
	ceroExt <= x"0000" & instr(15 downto 0); -- Extensión de cero
	
	inmExt <= ceroExt when extCero = '1' else signExt; -- Selector de extensión de signo o cero para dato inmediato de la ALU (aluB)

	aluB <= rd2 when aluSrc = '0' else inmExt; -- Selector entre dato inmediato o Rd2 del GPR
	
	
	MemDataAddr <= aluC; -- Dato a guardar en memoria de datos
	
	MemDataDataWrite <= rd2;
	
	MemDataWe <= memWrite; -- Habilitación de escritura en memoria de datos
	
	------------------------------CAMBIOS------------------------------
	
	--- Cambio de wd3 por muxMTR (salida del multiplexor de MemToReg)	
	
	muxMTR <= aluC when memToReg = '0' else MemDataDataRead; -- Resultado de ALU o memoria de datos.
	

	--- Multiplexor de PCToReg entre PCMas4 y wd3
	
	wd3 <= PCMas4 when pctoreg = '1' else muxMTR;
	
	--- Multiplexor de PCToReg entre $ra y regA3
	
	sA3 <= regA3 when pctoreg = '0' else "11111";

	
	MemProgAddr <= pc;
	
	pcSrc <= branch and flagZ;
	
	
	
	
	
	------------------- RUTA DEL PC --------------------------
	
	process(Clk, NRst) -- Completar lista de activación
	begin
		if NRst = '0' then -- Poner PC a 0 en caso de reset activo a nivel bajo.
			pc<=X"00000000";
		elsif rising_edge(CLK) then
			pc <= pcIn;
		end if;
	end process;    

	pcIn <= pcMas4(31 downto 28) & instr(25 downto 0) & "00" when Jump = '1' else pcInPre; -- Se guardará en pcIn la dirección de salto (j) o pcInPre
	
	pcInPre <= pcBranch when pcSrc = '1' else pcMas4; -- Se guardará en pcInPre la dirección de branch (beq) o el Pc+4 (instrucció normal)

	pcBranch <= PCMas4 + (signExt(29 downto 0) & "00"); -- La dirección de branch es la actual más la suma del número de palabras que indique el dato inmediato (extendido en signo porque puede sumar o restar)
	
	PCMas4 <= pc + 4;
	------------------- RUTA DEL PC --------------------------
	
	

end Practica;

