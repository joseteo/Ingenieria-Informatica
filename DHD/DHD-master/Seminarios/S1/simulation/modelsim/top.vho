-- Copyright (C) 2021  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and any partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details, at
-- https://fpgasoftware.intel.com/eula.

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 21.1.0 Build 842 10/21/2021 SJ Lite Edition"

-- DATE "03/11/2022 12:42:46"

-- 
-- Device: Altera EP4CE115F29C7 Package FBGA780
-- 

-- 
-- This VHDL file should be used for ModelSim (VHDL) only
-- 

LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	hard_block IS
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic
	);
END hard_block;

-- Design Ports Information
-- ~ALTERA_ASDO_DATA1~	=>  Location: PIN_F4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_FLASH_nCE_nCSO~	=>  Location: PIN_E2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DCLK~	=>  Location: PIN_P3,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_DATA0~	=>  Location: PIN_N7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- ~ALTERA_nCEO~	=>  Location: PIN_P28,	 I/O Standard: 2.5 V,	 Current Strength: 8mA


ARCHITECTURE structure OF hard_block IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~padout\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~padout\ : std_logic;
SIGNAL \~ALTERA_DATA0~~padout\ : std_logic;
SIGNAL \~ALTERA_ASDO_DATA1~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_FLASH_nCE_nCSO~~ibuf_o\ : std_logic;
SIGNAL \~ALTERA_DATA0~~ibuf_o\ : std_logic;

BEGIN

ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
END structure;


LIBRARY ALTERA;
LIBRARY CYCLONEIVE;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIVE.CYCLONEIVE_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Top IS
    PORT (
	Velocidad : IN std_logic_vector(2 DOWNTO 0);
	Reloj : IN std_logic;
	Reset : IN std_logic;
	SegDigit1 : BUFFER std_logic_vector(0 TO 6);
	SegDigit2 : BUFFER std_logic_vector(0 TO 6)
	);
END Top;

-- Design Ports Information
-- SegDigit1[6]	=>  Location: PIN_C14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit1[5]	=>  Location: PIN_D14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit1[4]	=>  Location: PIN_J14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit1[3]	=>  Location: PIN_D12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit1[2]	=>  Location: PIN_A12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit1[1]	=>  Location: PIN_G14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit1[0]	=>  Location: PIN_H14,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[6]	=>  Location: PIN_D15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[5]	=>  Location: PIN_C12,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[4]	=>  Location: PIN_C13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[3]	=>  Location: PIN_D13,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[2]	=>  Location: PIN_C15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[1]	=>  Location: PIN_F15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- SegDigit2[0]	=>  Location: PIN_E15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Reset	=>  Location: PIN_Y2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Velocidad[2]	=>  Location: PIN_AE15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Velocidad[1]	=>  Location: PIN_AC15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Velocidad[0]	=>  Location: PIN_AD15,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- Reloj	=>  Location: PIN_J1,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Top IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_Velocidad : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_Reloj : std_logic;
SIGNAL ww_Reset : std_logic;
SIGNAL ww_SegDigit1 : std_logic_vector(0 TO 6);
SIGNAL ww_SegDigit2 : std_logic_vector(0 TO 6);
SIGNAL \Reset~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \DivisorFrecuencia|Salida~clkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \Reloj~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \SegDigit1[6]~output_o\ : std_logic;
SIGNAL \SegDigit1[5]~output_o\ : std_logic;
SIGNAL \SegDigit1[4]~output_o\ : std_logic;
SIGNAL \SegDigit1[3]~output_o\ : std_logic;
SIGNAL \SegDigit1[2]~output_o\ : std_logic;
SIGNAL \SegDigit1[1]~output_o\ : std_logic;
SIGNAL \SegDigit1[0]~output_o\ : std_logic;
SIGNAL \SegDigit2[6]~output_o\ : std_logic;
SIGNAL \SegDigit2[5]~output_o\ : std_logic;
SIGNAL \SegDigit2[4]~output_o\ : std_logic;
SIGNAL \SegDigit2[3]~output_o\ : std_logic;
SIGNAL \SegDigit2[2]~output_o\ : std_logic;
SIGNAL \SegDigit2[1]~output_o\ : std_logic;
SIGNAL \SegDigit2[0]~output_o\ : std_logic;
SIGNAL \Reloj~input_o\ : std_logic;
SIGNAL \Reloj~inputclkctrl_outclk\ : std_logic;
SIGNAL \Velocidad[0]~input_o\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[0]~75_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[1]~25_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[1]~26\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[2]~27_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[2]~28\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[3]~29_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[3]~30\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[4]~31_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[4]~32\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[5]~33_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[5]~34\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[6]~35_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[6]~36\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[7]~37_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[7]~38\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[8]~39_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[8]~40\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[9]~41_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[9]~42\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[10]~43_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[10]~44\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[11]~45_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[11]~46\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[12]~47_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[12]~48\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[13]~49_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[13]~50\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[14]~51_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[14]~52\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[15]~53_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[15]~54\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[16]~55_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[16]~56\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[17]~57_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[17]~58\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[18]~59_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[18]~60\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[19]~61_combout\ : std_logic;
SIGNAL \Velocidad[2]~input_o\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[19]~62\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[20]~63_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[20]~64\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[21]~65_combout\ : std_logic;
SIGNAL \Velocidad[1]~input_o\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[21]~66\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[22]~67_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[22]~68\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[23]~69_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[23]~70\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[24]~71_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[24]~72\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador[25]~73_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida_int~2_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida_int~3_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida_int~0_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida_int~1_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida_int~4_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida~q\ : std_logic;
SIGNAL \DivisorFrecuencia|Salida~clkctrl_outclk\ : std_logic;
SIGNAL \Contador8|Contador[0]~21_combout\ : std_logic;
SIGNAL \Reset~input_o\ : std_logic;
SIGNAL \Reset~inputclkctrl_outclk\ : std_logic;
SIGNAL \Contador8|Contador[1]~7_combout\ : std_logic;
SIGNAL \Contador8|Contador[1]~8\ : std_logic;
SIGNAL \Contador8|Contador[2]~9_combout\ : std_logic;
SIGNAL \Contador8|Contador[2]~10\ : std_logic;
SIGNAL \Contador8|Contador[3]~11_combout\ : std_logic;
SIGNAL \Digito1|Mux6~0_combout\ : std_logic;
SIGNAL \Digito1|Mux5~0_combout\ : std_logic;
SIGNAL \Digito1|Mux4~0_combout\ : std_logic;
SIGNAL \Digito1|Mux3~0_combout\ : std_logic;
SIGNAL \Digito1|Mux2~0_combout\ : std_logic;
SIGNAL \Digito1|Mux1~0_combout\ : std_logic;
SIGNAL \Digito1|Mux0~0_combout\ : std_logic;
SIGNAL \Contador8|Contador[3]~12\ : std_logic;
SIGNAL \Contador8|Contador[4]~13_combout\ : std_logic;
SIGNAL \Contador8|Contador[4]~14\ : std_logic;
SIGNAL \Contador8|Contador[5]~15_combout\ : std_logic;
SIGNAL \Contador8|Contador[5]~16\ : std_logic;
SIGNAL \Contador8|Contador[6]~17_combout\ : std_logic;
SIGNAL \Contador8|Contador[6]~18\ : std_logic;
SIGNAL \Contador8|Contador[7]~19_combout\ : std_logic;
SIGNAL \Digito2|Mux6~0_combout\ : std_logic;
SIGNAL \Digito2|Mux5~0_combout\ : std_logic;
SIGNAL \Digito2|Mux4~0_combout\ : std_logic;
SIGNAL \Digito2|Mux3~0_combout\ : std_logic;
SIGNAL \Digito2|Mux2~0_combout\ : std_logic;
SIGNAL \Digito2|Mux1~0_combout\ : std_logic;
SIGNAL \Digito2|Mux0~0_combout\ : std_logic;
SIGNAL \DivisorFrecuencia|Contador\ : std_logic_vector(25 DOWNTO 0);
SIGNAL \Contador8|Contador\ : std_logic_vector(7 DOWNTO 0);
SIGNAL \ALT_INV_Reset~inputclkctrl_outclk\ : std_logic;
SIGNAL \Digito2|ALT_INV_Mux6~0_combout\ : std_logic;
SIGNAL \Digito1|ALT_INV_Mux6~0_combout\ : std_logic;

COMPONENT hard_block
    PORT (
	devoe : IN std_logic;
	devclrn : IN std_logic;
	devpor : IN std_logic);
END COMPONENT;

BEGIN

ww_Velocidad <= Velocidad;
ww_Reloj <= Reloj;
ww_Reset <= Reset;
SegDigit1 <= ww_SegDigit1;
SegDigit2 <= ww_SegDigit2;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\Reset~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \Reset~input_o\);

\DivisorFrecuencia|Salida~clkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \DivisorFrecuencia|Salida~q\);

\Reloj~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \Reloj~input_o\);
\ALT_INV_Reset~inputclkctrl_outclk\ <= NOT \Reset~inputclkctrl_outclk\;
\Digito2|ALT_INV_Mux6~0_combout\ <= NOT \Digito2|Mux6~0_combout\;
\Digito1|ALT_INV_Mux6~0_combout\ <= NOT \Digito1|Mux6~0_combout\;
auto_generated_inst : hard_block
PORT MAP (
	devoe => ww_devoe,
	devclrn => ww_devclrn,
	devpor => ww_devpor);

-- Location: IOOBUF_X52_Y73_N2
\SegDigit1[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|ALT_INV_Mux6~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[6]~output_o\);

-- Location: IOOBUF_X52_Y73_N9
\SegDigit1[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|Mux5~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[5]~output_o\);

-- Location: IOOBUF_X49_Y73_N23
\SegDigit1[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|Mux4~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[4]~output_o\);

-- Location: IOOBUF_X52_Y73_N23
\SegDigit1[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|Mux3~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[3]~output_o\);

-- Location: IOOBUF_X47_Y73_N2
\SegDigit1[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|Mux2~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[2]~output_o\);

-- Location: IOOBUF_X47_Y73_N16
\SegDigit1[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|Mux1~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[1]~output_o\);

-- Location: IOOBUF_X49_Y73_N16
\SegDigit1[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito1|Mux0~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit1[0]~output_o\);

-- Location: IOOBUF_X58_Y73_N23
\SegDigit2[6]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|ALT_INV_Mux6~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[6]~output_o\);

-- Location: IOOBUF_X52_Y73_N16
\SegDigit2[5]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|Mux5~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[5]~output_o\);

-- Location: IOOBUF_X54_Y73_N2
\SegDigit2[4]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|Mux4~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[4]~output_o\);

-- Location: IOOBUF_X54_Y73_N9
\SegDigit2[3]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|Mux3~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[3]~output_o\);

-- Location: IOOBUF_X58_Y73_N16
\SegDigit2[2]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|Mux2~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[2]~output_o\);

-- Location: IOOBUF_X58_Y73_N2
\SegDigit2[1]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|Mux1~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[1]~output_o\);

-- Location: IOOBUF_X58_Y73_N9
\SegDigit2[0]~output\ : cycloneive_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \Digito2|Mux0~0_combout\,
	devoe => ww_devoe,
	o => \SegDigit2[0]~output_o\);

-- Location: IOIBUF_X0_Y36_N8
\Reloj~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Reloj,
	o => \Reloj~input_o\);

-- Location: CLKCTRL_G2
\Reloj~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \Reloj~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \Reloj~inputclkctrl_outclk\);

-- Location: IOIBUF_X60_Y0_N15
\Velocidad[0]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Velocidad(0),
	o => \Velocidad[0]~input_o\);

-- Location: LCCOMB_X60_Y2_N4
\DivisorFrecuencia|Contador[0]~75\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[0]~75_combout\ = !\DivisorFrecuencia|Contador\(0)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \DivisorFrecuencia|Contador\(0),
	combout => \DivisorFrecuencia|Contador[0]~75_combout\);

-- Location: FF_X60_Y2_N5
\DivisorFrecuencia|Contador[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[0]~75_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(0));

-- Location: LCCOMB_X60_Y2_N8
\DivisorFrecuencia|Contador[1]~25\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[1]~25_combout\ = (\DivisorFrecuencia|Contador\(0) & (\DivisorFrecuencia|Contador\(1) $ (VCC))) # (!\DivisorFrecuencia|Contador\(0) & (\DivisorFrecuencia|Contador\(1) & VCC))
-- \DivisorFrecuencia|Contador[1]~26\ = CARRY((\DivisorFrecuencia|Contador\(0) & \DivisorFrecuencia|Contador\(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(0),
	datab => \DivisorFrecuencia|Contador\(1),
	datad => VCC,
	combout => \DivisorFrecuencia|Contador[1]~25_combout\,
	cout => \DivisorFrecuencia|Contador[1]~26\);

-- Location: FF_X60_Y2_N9
\DivisorFrecuencia|Contador[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[1]~25_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(1));

-- Location: LCCOMB_X60_Y2_N10
\DivisorFrecuencia|Contador[2]~27\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[2]~27_combout\ = (\DivisorFrecuencia|Contador\(2) & (!\DivisorFrecuencia|Contador[1]~26\)) # (!\DivisorFrecuencia|Contador\(2) & ((\DivisorFrecuencia|Contador[1]~26\) # (GND)))
-- \DivisorFrecuencia|Contador[2]~28\ = CARRY((!\DivisorFrecuencia|Contador[1]~26\) # (!\DivisorFrecuencia|Contador\(2)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(2),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[1]~26\,
	combout => \DivisorFrecuencia|Contador[2]~27_combout\,
	cout => \DivisorFrecuencia|Contador[2]~28\);

-- Location: FF_X60_Y2_N11
\DivisorFrecuencia|Contador[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[2]~27_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(2));

-- Location: LCCOMB_X60_Y2_N12
\DivisorFrecuencia|Contador[3]~29\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[3]~29_combout\ = (\DivisorFrecuencia|Contador\(3) & (\DivisorFrecuencia|Contador[2]~28\ $ (GND))) # (!\DivisorFrecuencia|Contador\(3) & (!\DivisorFrecuencia|Contador[2]~28\ & VCC))
-- \DivisorFrecuencia|Contador[3]~30\ = CARRY((\DivisorFrecuencia|Contador\(3) & !\DivisorFrecuencia|Contador[2]~28\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(3),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[2]~28\,
	combout => \DivisorFrecuencia|Contador[3]~29_combout\,
	cout => \DivisorFrecuencia|Contador[3]~30\);

-- Location: FF_X60_Y2_N13
\DivisorFrecuencia|Contador[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[3]~29_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(3));

-- Location: LCCOMB_X60_Y2_N14
\DivisorFrecuencia|Contador[4]~31\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[4]~31_combout\ = (\DivisorFrecuencia|Contador\(4) & (!\DivisorFrecuencia|Contador[3]~30\)) # (!\DivisorFrecuencia|Contador\(4) & ((\DivisorFrecuencia|Contador[3]~30\) # (GND)))
-- \DivisorFrecuencia|Contador[4]~32\ = CARRY((!\DivisorFrecuencia|Contador[3]~30\) # (!\DivisorFrecuencia|Contador\(4)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(4),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[3]~30\,
	combout => \DivisorFrecuencia|Contador[4]~31_combout\,
	cout => \DivisorFrecuencia|Contador[4]~32\);

-- Location: FF_X60_Y2_N15
\DivisorFrecuencia|Contador[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[4]~31_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(4));

-- Location: LCCOMB_X60_Y2_N16
\DivisorFrecuencia|Contador[5]~33\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[5]~33_combout\ = (\DivisorFrecuencia|Contador\(5) & (\DivisorFrecuencia|Contador[4]~32\ $ (GND))) # (!\DivisorFrecuencia|Contador\(5) & (!\DivisorFrecuencia|Contador[4]~32\ & VCC))
-- \DivisorFrecuencia|Contador[5]~34\ = CARRY((\DivisorFrecuencia|Contador\(5) & !\DivisorFrecuencia|Contador[4]~32\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(5),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[4]~32\,
	combout => \DivisorFrecuencia|Contador[5]~33_combout\,
	cout => \DivisorFrecuencia|Contador[5]~34\);

-- Location: FF_X60_Y2_N17
\DivisorFrecuencia|Contador[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[5]~33_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(5));

-- Location: LCCOMB_X60_Y2_N18
\DivisorFrecuencia|Contador[6]~35\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[6]~35_combout\ = (\DivisorFrecuencia|Contador\(6) & (!\DivisorFrecuencia|Contador[5]~34\)) # (!\DivisorFrecuencia|Contador\(6) & ((\DivisorFrecuencia|Contador[5]~34\) # (GND)))
-- \DivisorFrecuencia|Contador[6]~36\ = CARRY((!\DivisorFrecuencia|Contador[5]~34\) # (!\DivisorFrecuencia|Contador\(6)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(6),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[5]~34\,
	combout => \DivisorFrecuencia|Contador[6]~35_combout\,
	cout => \DivisorFrecuencia|Contador[6]~36\);

-- Location: FF_X60_Y2_N19
\DivisorFrecuencia|Contador[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[6]~35_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(6));

-- Location: LCCOMB_X60_Y2_N20
\DivisorFrecuencia|Contador[7]~37\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[7]~37_combout\ = (\DivisorFrecuencia|Contador\(7) & (\DivisorFrecuencia|Contador[6]~36\ $ (GND))) # (!\DivisorFrecuencia|Contador\(7) & (!\DivisorFrecuencia|Contador[6]~36\ & VCC))
-- \DivisorFrecuencia|Contador[7]~38\ = CARRY((\DivisorFrecuencia|Contador\(7) & !\DivisorFrecuencia|Contador[6]~36\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(7),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[6]~36\,
	combout => \DivisorFrecuencia|Contador[7]~37_combout\,
	cout => \DivisorFrecuencia|Contador[7]~38\);

-- Location: FF_X60_Y2_N21
\DivisorFrecuencia|Contador[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[7]~37_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(7));

-- Location: LCCOMB_X60_Y2_N22
\DivisorFrecuencia|Contador[8]~39\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[8]~39_combout\ = (\DivisorFrecuencia|Contador\(8) & (!\DivisorFrecuencia|Contador[7]~38\)) # (!\DivisorFrecuencia|Contador\(8) & ((\DivisorFrecuencia|Contador[7]~38\) # (GND)))
-- \DivisorFrecuencia|Contador[8]~40\ = CARRY((!\DivisorFrecuencia|Contador[7]~38\) # (!\DivisorFrecuencia|Contador\(8)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(8),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[7]~38\,
	combout => \DivisorFrecuencia|Contador[8]~39_combout\,
	cout => \DivisorFrecuencia|Contador[8]~40\);

-- Location: FF_X60_Y2_N23
\DivisorFrecuencia|Contador[8]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[8]~39_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(8));

-- Location: LCCOMB_X60_Y2_N24
\DivisorFrecuencia|Contador[9]~41\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[9]~41_combout\ = (\DivisorFrecuencia|Contador\(9) & (\DivisorFrecuencia|Contador[8]~40\ $ (GND))) # (!\DivisorFrecuencia|Contador\(9) & (!\DivisorFrecuencia|Contador[8]~40\ & VCC))
-- \DivisorFrecuencia|Contador[9]~42\ = CARRY((\DivisorFrecuencia|Contador\(9) & !\DivisorFrecuencia|Contador[8]~40\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(9),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[8]~40\,
	combout => \DivisorFrecuencia|Contador[9]~41_combout\,
	cout => \DivisorFrecuencia|Contador[9]~42\);

-- Location: FF_X60_Y2_N25
\DivisorFrecuencia|Contador[9]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[9]~41_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(9));

-- Location: LCCOMB_X60_Y2_N26
\DivisorFrecuencia|Contador[10]~43\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[10]~43_combout\ = (\DivisorFrecuencia|Contador\(10) & (!\DivisorFrecuencia|Contador[9]~42\)) # (!\DivisorFrecuencia|Contador\(10) & ((\DivisorFrecuencia|Contador[9]~42\) # (GND)))
-- \DivisorFrecuencia|Contador[10]~44\ = CARRY((!\DivisorFrecuencia|Contador[9]~42\) # (!\DivisorFrecuencia|Contador\(10)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(10),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[9]~42\,
	combout => \DivisorFrecuencia|Contador[10]~43_combout\,
	cout => \DivisorFrecuencia|Contador[10]~44\);

-- Location: FF_X60_Y2_N27
\DivisorFrecuencia|Contador[10]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[10]~43_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(10));

-- Location: LCCOMB_X60_Y2_N28
\DivisorFrecuencia|Contador[11]~45\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[11]~45_combout\ = (\DivisorFrecuencia|Contador\(11) & (\DivisorFrecuencia|Contador[10]~44\ $ (GND))) # (!\DivisorFrecuencia|Contador\(11) & (!\DivisorFrecuencia|Contador[10]~44\ & VCC))
-- \DivisorFrecuencia|Contador[11]~46\ = CARRY((\DivisorFrecuencia|Contador\(11) & !\DivisorFrecuencia|Contador[10]~44\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(11),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[10]~44\,
	combout => \DivisorFrecuencia|Contador[11]~45_combout\,
	cout => \DivisorFrecuencia|Contador[11]~46\);

-- Location: FF_X60_Y2_N29
\DivisorFrecuencia|Contador[11]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[11]~45_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(11));

-- Location: LCCOMB_X60_Y2_N30
\DivisorFrecuencia|Contador[12]~47\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[12]~47_combout\ = (\DivisorFrecuencia|Contador\(12) & (!\DivisorFrecuencia|Contador[11]~46\)) # (!\DivisorFrecuencia|Contador\(12) & ((\DivisorFrecuencia|Contador[11]~46\) # (GND)))
-- \DivisorFrecuencia|Contador[12]~48\ = CARRY((!\DivisorFrecuencia|Contador[11]~46\) # (!\DivisorFrecuencia|Contador\(12)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(12),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[11]~46\,
	combout => \DivisorFrecuencia|Contador[12]~47_combout\,
	cout => \DivisorFrecuencia|Contador[12]~48\);

-- Location: FF_X60_Y2_N31
\DivisorFrecuencia|Contador[12]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[12]~47_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(12));

-- Location: LCCOMB_X60_Y1_N0
\DivisorFrecuencia|Contador[13]~49\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[13]~49_combout\ = (\DivisorFrecuencia|Contador\(13) & (\DivisorFrecuencia|Contador[12]~48\ $ (GND))) # (!\DivisorFrecuencia|Contador\(13) & (!\DivisorFrecuencia|Contador[12]~48\ & VCC))
-- \DivisorFrecuencia|Contador[13]~50\ = CARRY((\DivisorFrecuencia|Contador\(13) & !\DivisorFrecuencia|Contador[12]~48\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(13),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[12]~48\,
	combout => \DivisorFrecuencia|Contador[13]~49_combout\,
	cout => \DivisorFrecuencia|Contador[13]~50\);

-- Location: FF_X60_Y1_N1
\DivisorFrecuencia|Contador[13]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[13]~49_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(13));

-- Location: LCCOMB_X60_Y1_N2
\DivisorFrecuencia|Contador[14]~51\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[14]~51_combout\ = (\DivisorFrecuencia|Contador\(14) & (!\DivisorFrecuencia|Contador[13]~50\)) # (!\DivisorFrecuencia|Contador\(14) & ((\DivisorFrecuencia|Contador[13]~50\) # (GND)))
-- \DivisorFrecuencia|Contador[14]~52\ = CARRY((!\DivisorFrecuencia|Contador[13]~50\) # (!\DivisorFrecuencia|Contador\(14)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(14),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[13]~50\,
	combout => \DivisorFrecuencia|Contador[14]~51_combout\,
	cout => \DivisorFrecuencia|Contador[14]~52\);

-- Location: FF_X60_Y1_N3
\DivisorFrecuencia|Contador[14]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[14]~51_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(14));

-- Location: LCCOMB_X60_Y1_N4
\DivisorFrecuencia|Contador[15]~53\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[15]~53_combout\ = (\DivisorFrecuencia|Contador\(15) & (\DivisorFrecuencia|Contador[14]~52\ $ (GND))) # (!\DivisorFrecuencia|Contador\(15) & (!\DivisorFrecuencia|Contador[14]~52\ & VCC))
-- \DivisorFrecuencia|Contador[15]~54\ = CARRY((\DivisorFrecuencia|Contador\(15) & !\DivisorFrecuencia|Contador[14]~52\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(15),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[14]~52\,
	combout => \DivisorFrecuencia|Contador[15]~53_combout\,
	cout => \DivisorFrecuencia|Contador[15]~54\);

-- Location: FF_X60_Y1_N5
\DivisorFrecuencia|Contador[15]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[15]~53_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(15));

-- Location: LCCOMB_X60_Y1_N6
\DivisorFrecuencia|Contador[16]~55\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[16]~55_combout\ = (\DivisorFrecuencia|Contador\(16) & (!\DivisorFrecuencia|Contador[15]~54\)) # (!\DivisorFrecuencia|Contador\(16) & ((\DivisorFrecuencia|Contador[15]~54\) # (GND)))
-- \DivisorFrecuencia|Contador[16]~56\ = CARRY((!\DivisorFrecuencia|Contador[15]~54\) # (!\DivisorFrecuencia|Contador\(16)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(16),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[15]~54\,
	combout => \DivisorFrecuencia|Contador[16]~55_combout\,
	cout => \DivisorFrecuencia|Contador[16]~56\);

-- Location: FF_X60_Y1_N7
\DivisorFrecuencia|Contador[16]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[16]~55_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(16));

-- Location: LCCOMB_X60_Y1_N8
\DivisorFrecuencia|Contador[17]~57\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[17]~57_combout\ = (\DivisorFrecuencia|Contador\(17) & (\DivisorFrecuencia|Contador[16]~56\ $ (GND))) # (!\DivisorFrecuencia|Contador\(17) & (!\DivisorFrecuencia|Contador[16]~56\ & VCC))
-- \DivisorFrecuencia|Contador[17]~58\ = CARRY((\DivisorFrecuencia|Contador\(17) & !\DivisorFrecuencia|Contador[16]~56\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(17),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[16]~56\,
	combout => \DivisorFrecuencia|Contador[17]~57_combout\,
	cout => \DivisorFrecuencia|Contador[17]~58\);

-- Location: FF_X60_Y1_N9
\DivisorFrecuencia|Contador[17]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[17]~57_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(17));

-- Location: LCCOMB_X60_Y1_N10
\DivisorFrecuencia|Contador[18]~59\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[18]~59_combout\ = (\DivisorFrecuencia|Contador\(18) & (!\DivisorFrecuencia|Contador[17]~58\)) # (!\DivisorFrecuencia|Contador\(18) & ((\DivisorFrecuencia|Contador[17]~58\) # (GND)))
-- \DivisorFrecuencia|Contador[18]~60\ = CARRY((!\DivisorFrecuencia|Contador[17]~58\) # (!\DivisorFrecuencia|Contador\(18)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(18),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[17]~58\,
	combout => \DivisorFrecuencia|Contador[18]~59_combout\,
	cout => \DivisorFrecuencia|Contador[18]~60\);

-- Location: FF_X60_Y1_N11
\DivisorFrecuencia|Contador[18]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[18]~59_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(18));

-- Location: LCCOMB_X60_Y1_N12
\DivisorFrecuencia|Contador[19]~61\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[19]~61_combout\ = (\DivisorFrecuencia|Contador\(19) & (\DivisorFrecuencia|Contador[18]~60\ $ (GND))) # (!\DivisorFrecuencia|Contador\(19) & (!\DivisorFrecuencia|Contador[18]~60\ & VCC))
-- \DivisorFrecuencia|Contador[19]~62\ = CARRY((\DivisorFrecuencia|Contador\(19) & !\DivisorFrecuencia|Contador[18]~60\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(19),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[18]~60\,
	combout => \DivisorFrecuencia|Contador[19]~61_combout\,
	cout => \DivisorFrecuencia|Contador[19]~62\);

-- Location: FF_X60_Y1_N13
\DivisorFrecuencia|Contador[19]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[19]~61_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(19));

-- Location: IOIBUF_X60_Y0_N8
\Velocidad[2]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Velocidad(2),
	o => \Velocidad[2]~input_o\);

-- Location: LCCOMB_X60_Y1_N14
\DivisorFrecuencia|Contador[20]~63\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[20]~63_combout\ = (\DivisorFrecuencia|Contador\(20) & (!\DivisorFrecuencia|Contador[19]~62\)) # (!\DivisorFrecuencia|Contador\(20) & ((\DivisorFrecuencia|Contador[19]~62\) # (GND)))
-- \DivisorFrecuencia|Contador[20]~64\ = CARRY((!\DivisorFrecuencia|Contador[19]~62\) # (!\DivisorFrecuencia|Contador\(20)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(20),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[19]~62\,
	combout => \DivisorFrecuencia|Contador[20]~63_combout\,
	cout => \DivisorFrecuencia|Contador[20]~64\);

-- Location: FF_X60_Y1_N15
\DivisorFrecuencia|Contador[20]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[20]~63_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(20));

-- Location: LCCOMB_X60_Y1_N16
\DivisorFrecuencia|Contador[21]~65\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[21]~65_combout\ = (\DivisorFrecuencia|Contador\(21) & (\DivisorFrecuencia|Contador[20]~64\ $ (GND))) # (!\DivisorFrecuencia|Contador\(21) & (!\DivisorFrecuencia|Contador[20]~64\ & VCC))
-- \DivisorFrecuencia|Contador[21]~66\ = CARRY((\DivisorFrecuencia|Contador\(21) & !\DivisorFrecuencia|Contador[20]~64\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(21),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[20]~64\,
	combout => \DivisorFrecuencia|Contador[21]~65_combout\,
	cout => \DivisorFrecuencia|Contador[21]~66\);

-- Location: FF_X60_Y1_N17
\DivisorFrecuencia|Contador[21]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[21]~65_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(21));

-- Location: IOIBUF_X60_Y0_N22
\Velocidad[1]~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Velocidad(1),
	o => \Velocidad[1]~input_o\);

-- Location: LCCOMB_X60_Y1_N18
\DivisorFrecuencia|Contador[22]~67\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[22]~67_combout\ = (\DivisorFrecuencia|Contador\(22) & (!\DivisorFrecuencia|Contador[21]~66\)) # (!\DivisorFrecuencia|Contador\(22) & ((\DivisorFrecuencia|Contador[21]~66\) # (GND)))
-- \DivisorFrecuencia|Contador[22]~68\ = CARRY((!\DivisorFrecuencia|Contador[21]~66\) # (!\DivisorFrecuencia|Contador\(22)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(22),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[21]~66\,
	combout => \DivisorFrecuencia|Contador[22]~67_combout\,
	cout => \DivisorFrecuencia|Contador[22]~68\);

-- Location: FF_X60_Y1_N19
\DivisorFrecuencia|Contador[22]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[22]~67_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(22));

-- Location: LCCOMB_X60_Y1_N20
\DivisorFrecuencia|Contador[23]~69\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[23]~69_combout\ = (\DivisorFrecuencia|Contador\(23) & (\DivisorFrecuencia|Contador[22]~68\ $ (GND))) # (!\DivisorFrecuencia|Contador\(23) & (!\DivisorFrecuencia|Contador[22]~68\ & VCC))
-- \DivisorFrecuencia|Contador[23]~70\ = CARRY((\DivisorFrecuencia|Contador\(23) & !\DivisorFrecuencia|Contador[22]~68\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \DivisorFrecuencia|Contador\(23),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[22]~68\,
	combout => \DivisorFrecuencia|Contador[23]~69_combout\,
	cout => \DivisorFrecuencia|Contador[23]~70\);

-- Location: FF_X60_Y1_N21
\DivisorFrecuencia|Contador[23]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[23]~69_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(23));

-- Location: LCCOMB_X60_Y1_N22
\DivisorFrecuencia|Contador[24]~71\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[24]~71_combout\ = (\DivisorFrecuencia|Contador\(24) & (!\DivisorFrecuencia|Contador[23]~70\)) # (!\DivisorFrecuencia|Contador\(24) & ((\DivisorFrecuencia|Contador[23]~70\) # (GND)))
-- \DivisorFrecuencia|Contador[24]~72\ = CARRY((!\DivisorFrecuencia|Contador[23]~70\) # (!\DivisorFrecuencia|Contador\(24)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(24),
	datad => VCC,
	cin => \DivisorFrecuencia|Contador[23]~70\,
	combout => \DivisorFrecuencia|Contador[24]~71_combout\,
	cout => \DivisorFrecuencia|Contador[24]~72\);

-- Location: FF_X60_Y1_N23
\DivisorFrecuencia|Contador[24]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[24]~71_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(24));

-- Location: LCCOMB_X60_Y1_N24
\DivisorFrecuencia|Contador[25]~73\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Contador[25]~73_combout\ = \DivisorFrecuencia|Contador[24]~72\ $ (!\DivisorFrecuencia|Contador\(25))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => \DivisorFrecuencia|Contador\(25),
	cin => \DivisorFrecuencia|Contador[24]~72\,
	combout => \DivisorFrecuencia|Contador[25]~73_combout\);

-- Location: FF_X60_Y1_N25
\DivisorFrecuencia|Contador[25]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Contador[25]~73_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Contador\(25));

-- Location: LCCOMB_X60_Y1_N28
\DivisorFrecuencia|Salida_int~2\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Salida_int~2_combout\ = (\Velocidad[2]~input_o\ & ((\DivisorFrecuencia|Contador\(21)) # ((\Velocidad[1]~input_o\)))) # (!\Velocidad[2]~input_o\ & (((!\Velocidad[1]~input_o\ & \DivisorFrecuencia|Contador\(25)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110110101000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Velocidad[2]~input_o\,
	datab => \DivisorFrecuencia|Contador\(21),
	datac => \Velocidad[1]~input_o\,
	datad => \DivisorFrecuencia|Contador\(25),
	combout => \DivisorFrecuencia|Salida_int~2_combout\);

-- Location: LCCOMB_X60_Y1_N30
\DivisorFrecuencia|Salida_int~3\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Salida_int~3_combout\ = (\DivisorFrecuencia|Salida_int~2_combout\ & ((\DivisorFrecuencia|Contador\(19)) # ((!\Velocidad[1]~input_o\)))) # (!\DivisorFrecuencia|Salida_int~2_combout\ & (((\Velocidad[1]~input_o\ & 
-- \DivisorFrecuencia|Contador\(23)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1011110010001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \DivisorFrecuencia|Contador\(19),
	datab => \DivisorFrecuencia|Salida_int~2_combout\,
	datac => \Velocidad[1]~input_o\,
	datad => \DivisorFrecuencia|Contador\(23),
	combout => \DivisorFrecuencia|Salida_int~3_combout\);

-- Location: LCCOMB_X60_Y1_N26
\DivisorFrecuencia|Salida_int~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Salida_int~0_combout\ = (\Velocidad[2]~input_o\ & (\Velocidad[1]~input_o\)) # (!\Velocidad[2]~input_o\ & ((\Velocidad[1]~input_o\ & ((\DivisorFrecuencia|Contador\(22)))) # (!\Velocidad[1]~input_o\ & (\DivisorFrecuencia|Contador\(24)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1101110010011000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Velocidad[2]~input_o\,
	datab => \Velocidad[1]~input_o\,
	datac => \DivisorFrecuencia|Contador\(24),
	datad => \DivisorFrecuencia|Contador\(22),
	combout => \DivisorFrecuencia|Salida_int~0_combout\);

-- Location: LCCOMB_X59_Y1_N18
\DivisorFrecuencia|Salida_int~1\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Salida_int~1_combout\ = (\Velocidad[2]~input_o\ & ((\DivisorFrecuencia|Salida_int~0_combout\ & ((\DivisorFrecuencia|Contador\(18)))) # (!\DivisorFrecuencia|Salida_int~0_combout\ & (\DivisorFrecuencia|Contador\(20))))) # 
-- (!\Velocidad[2]~input_o\ & (((\DivisorFrecuencia|Salida_int~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111010110001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Velocidad[2]~input_o\,
	datab => \DivisorFrecuencia|Contador\(20),
	datac => \DivisorFrecuencia|Contador\(18),
	datad => \DivisorFrecuencia|Salida_int~0_combout\,
	combout => \DivisorFrecuencia|Salida_int~1_combout\);

-- Location: LCCOMB_X59_Y1_N30
\DivisorFrecuencia|Salida_int~4\ : cycloneive_lcell_comb
-- Equation(s):
-- \DivisorFrecuencia|Salida_int~4_combout\ = (\Velocidad[0]~input_o\ & ((\DivisorFrecuencia|Salida_int~1_combout\))) # (!\Velocidad[0]~input_o\ & (\DivisorFrecuencia|Salida_int~3_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110000110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \Velocidad[0]~input_o\,
	datac => \DivisorFrecuencia|Salida_int~3_combout\,
	datad => \DivisorFrecuencia|Salida_int~1_combout\,
	combout => \DivisorFrecuencia|Salida_int~4_combout\);

-- Location: FF_X59_Y1_N31
\DivisorFrecuencia|Salida\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \Reloj~inputclkctrl_outclk\,
	d => \DivisorFrecuencia|Salida_int~4_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \DivisorFrecuencia|Salida~q\);

-- Location: CLKCTRL_G16
\DivisorFrecuencia|Salida~clkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \DivisorFrecuencia|Salida~clkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \DivisorFrecuencia|Salida~clkctrl_outclk\);

-- Location: LCCOMB_X53_Y72_N0
\Contador8|Contador[0]~21\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[0]~21_combout\ = !\Contador8|Contador\(0)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100001111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \Contador8|Contador\(0),
	combout => \Contador8|Contador[0]~21_combout\);

-- Location: IOIBUF_X0_Y36_N15
\Reset~input\ : cycloneive_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_Reset,
	o => \Reset~input_o\);

-- Location: CLKCTRL_G4
\Reset~inputclkctrl\ : cycloneive_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \Reset~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \Reset~inputclkctrl_outclk\);

-- Location: FF_X53_Y72_N1
\Contador8|Contador[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[0]~21_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(0));

-- Location: LCCOMB_X53_Y72_N8
\Contador8|Contador[1]~7\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[1]~7_combout\ = (\Contador8|Contador\(1) & (\Contador8|Contador\(0) $ (VCC))) # (!\Contador8|Contador\(1) & (\Contador8|Contador\(0) & VCC))
-- \Contador8|Contador[1]~8\ = CARRY((\Contador8|Contador\(1) & \Contador8|Contador\(0)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110011010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(0),
	datad => VCC,
	combout => \Contador8|Contador[1]~7_combout\,
	cout => \Contador8|Contador[1]~8\);

-- Location: FF_X53_Y72_N9
\Contador8|Contador[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[1]~7_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(1));

-- Location: LCCOMB_X53_Y72_N10
\Contador8|Contador[2]~9\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[2]~9_combout\ = (\Contador8|Contador\(2) & (!\Contador8|Contador[1]~8\)) # (!\Contador8|Contador\(2) & ((\Contador8|Contador[1]~8\) # (GND)))
-- \Contador8|Contador[2]~10\ = CARRY((!\Contador8|Contador[1]~8\) # (!\Contador8|Contador\(2)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101101001011111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(2),
	datad => VCC,
	cin => \Contador8|Contador[1]~8\,
	combout => \Contador8|Contador[2]~9_combout\,
	cout => \Contador8|Contador[2]~10\);

-- Location: FF_X53_Y72_N11
\Contador8|Contador[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[2]~9_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(2));

-- Location: LCCOMB_X53_Y72_N12
\Contador8|Contador[3]~11\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[3]~11_combout\ = (\Contador8|Contador\(3) & (\Contador8|Contador[2]~10\ $ (GND))) # (!\Contador8|Contador\(3) & (!\Contador8|Contador[2]~10\ & VCC))
-- \Contador8|Contador[3]~12\ = CARRY((\Contador8|Contador\(3) & !\Contador8|Contador[2]~10\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(3),
	datad => VCC,
	cin => \Contador8|Contador[2]~10\,
	combout => \Contador8|Contador[3]~11_combout\,
	cout => \Contador8|Contador[3]~12\);

-- Location: FF_X53_Y72_N13
\Contador8|Contador[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[3]~11_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(3));

-- Location: LCCOMB_X53_Y72_N6
\Digito1|Mux6~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux6~0_combout\ = (\Contador8|Contador\(0) & ((\Contador8|Contador\(3)) # (\Contador8|Contador\(1) $ (\Contador8|Contador\(2))))) # (!\Contador8|Contador\(0) & ((\Contador8|Contador\(1)) # (\Contador8|Contador\(2) $ (\Contador8|Contador\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101101101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux6~0_combout\);

-- Location: LCCOMB_X53_Y72_N28
\Digito1|Mux5~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux5~0_combout\ = (\Contador8|Contador\(1) & (!\Contador8|Contador\(3) & ((\Contador8|Contador\(0)) # (!\Contador8|Contador\(2))))) # (!\Contador8|Contador\(1) & (\Contador8|Contador\(0) & (\Contador8|Contador\(2) $ (!\Contador8|Contador\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000010110010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux5~0_combout\);

-- Location: LCCOMB_X53_Y72_N26
\Digito1|Mux4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux4~0_combout\ = (\Contador8|Contador\(1) & (((\Contador8|Contador\(0) & !\Contador8|Contador\(3))))) # (!\Contador8|Contador\(1) & ((\Contador8|Contador\(2) & ((!\Contador8|Contador\(3)))) # (!\Contador8|Contador\(2) & 
-- (\Contador8|Contador\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001000011110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux4~0_combout\);

-- Location: LCCOMB_X53_Y72_N2
\Digito1|Mux3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux3~0_combout\ = (\Contador8|Contador\(1) & ((\Contador8|Contador\(2) & (\Contador8|Contador\(0))) # (!\Contador8|Contador\(2) & (!\Contador8|Contador\(0) & \Contador8|Contador\(3))))) # (!\Contador8|Contador\(1) & (!\Contador8|Contador\(3) & 
-- (\Contador8|Contador\(2) $ (\Contador8|Contador\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000001010010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux3~0_combout\);

-- Location: LCCOMB_X53_Y72_N24
\Digito1|Mux2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux2~0_combout\ = (\Contador8|Contador\(2) & (\Contador8|Contador\(3) & ((\Contador8|Contador\(1)) # (!\Contador8|Contador\(0))))) # (!\Contador8|Contador\(2) & (\Contador8|Contador\(1) & (!\Contador8|Contador\(0) & !\Contador8|Contador\(3))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000110000000010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux2~0_combout\);

-- Location: LCCOMB_X53_Y72_N30
\Digito1|Mux1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux1~0_combout\ = (\Contador8|Contador\(1) & ((\Contador8|Contador\(0) & ((\Contador8|Contador\(3)))) # (!\Contador8|Contador\(0) & (\Contador8|Contador\(2))))) # (!\Contador8|Contador\(1) & (\Contador8|Contador\(2) & (\Contador8|Contador\(0) $ 
-- (\Contador8|Contador\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110001001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux1~0_combout\);

-- Location: LCCOMB_X53_Y72_N4
\Digito1|Mux0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito1|Mux0~0_combout\ = (\Contador8|Contador\(2) & (!\Contador8|Contador\(1) & (\Contador8|Contador\(0) $ (!\Contador8|Contador\(3))))) # (!\Contador8|Contador\(2) & (\Contador8|Contador\(0) & (\Contador8|Contador\(1) $ (!\Contador8|Contador\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0110000000010100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(1),
	datab => \Contador8|Contador\(2),
	datac => \Contador8|Contador\(0),
	datad => \Contador8|Contador\(3),
	combout => \Digito1|Mux0~0_combout\);

-- Location: LCCOMB_X53_Y72_N14
\Contador8|Contador[4]~13\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[4]~13_combout\ = (\Contador8|Contador\(4) & (!\Contador8|Contador[3]~12\)) # (!\Contador8|Contador\(4) & ((\Contador8|Contador[3]~12\) # (GND)))
-- \Contador8|Contador[4]~14\ = CARRY((!\Contador8|Contador[3]~12\) # (!\Contador8|Contador\(4)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \Contador8|Contador\(4),
	datad => VCC,
	cin => \Contador8|Contador[3]~12\,
	combout => \Contador8|Contador[4]~13_combout\,
	cout => \Contador8|Contador[4]~14\);

-- Location: FF_X53_Y72_N15
\Contador8|Contador[4]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[4]~13_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(4));

-- Location: LCCOMB_X53_Y72_N16
\Contador8|Contador[5]~15\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[5]~15_combout\ = (\Contador8|Contador\(5) & (\Contador8|Contador[4]~14\ $ (GND))) # (!\Contador8|Contador\(5) & (!\Contador8|Contador[4]~14\ & VCC))
-- \Contador8|Contador[5]~16\ = CARRY((\Contador8|Contador\(5) & !\Contador8|Contador[4]~14\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001100001100",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \Contador8|Contador\(5),
	datad => VCC,
	cin => \Contador8|Contador[4]~14\,
	combout => \Contador8|Contador[5]~15_combout\,
	cout => \Contador8|Contador[5]~16\);

-- Location: FF_X53_Y72_N17
\Contador8|Contador[5]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[5]~15_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(5));

-- Location: LCCOMB_X53_Y72_N18
\Contador8|Contador[6]~17\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[6]~17_combout\ = (\Contador8|Contador\(6) & (!\Contador8|Contador[5]~16\)) # (!\Contador8|Contador\(6) & ((\Contador8|Contador[5]~16\) # (GND)))
-- \Contador8|Contador[6]~18\ = CARRY((!\Contador8|Contador[5]~16\) # (!\Contador8|Contador\(6)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \Contador8|Contador\(6),
	datad => VCC,
	cin => \Contador8|Contador[5]~16\,
	combout => \Contador8|Contador[6]~17_combout\,
	cout => \Contador8|Contador[6]~18\);

-- Location: FF_X53_Y72_N19
\Contador8|Contador[6]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[6]~17_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(6));

-- Location: LCCOMB_X53_Y72_N20
\Contador8|Contador[7]~19\ : cycloneive_lcell_comb
-- Equation(s):
-- \Contador8|Contador[7]~19_combout\ = \Contador8|Contador[6]~18\ $ (!\Contador8|Contador\(7))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000001111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datad => \Contador8|Contador\(7),
	cin => \Contador8|Contador[6]~18\,
	combout => \Contador8|Contador[7]~19_combout\);

-- Location: FF_X53_Y72_N21
\Contador8|Contador[7]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \DivisorFrecuencia|Salida~clkctrl_outclk\,
	d => \Contador8|Contador[7]~19_combout\,
	clrn => \ALT_INV_Reset~inputclkctrl_outclk\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \Contador8|Contador\(7));

-- Location: LCCOMB_X54_Y72_N24
\Digito2|Mux6~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux6~0_combout\ = (\Contador8|Contador\(4) & ((\Contador8|Contador\(7)) # (\Contador8|Contador\(6) $ (\Contador8|Contador\(5))))) # (!\Contador8|Contador\(4) & ((\Contador8|Contador\(5)) # (\Contador8|Contador\(6) $ (\Contador8|Contador\(7)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111101101111100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(6),
	datac => \Contador8|Contador\(5),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux6~0_combout\);

-- Location: LCCOMB_X53_Y72_N22
\Digito2|Mux5~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux5~0_combout\ = (\Contador8|Contador\(4) & (\Contador8|Contador\(7) $ (((\Contador8|Contador\(5)) # (!\Contador8|Contador\(6)))))) # (!\Contador8|Contador\(4) & (\Contador8|Contador\(5) & (!\Contador8|Contador\(6) & !\Contador8|Contador\(7))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010000010001110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(5),
	datac => \Contador8|Contador\(6),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux5~0_combout\);

-- Location: LCCOMB_X54_Y72_N2
\Digito2|Mux4~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux4~0_combout\ = (\Contador8|Contador\(5) & (\Contador8|Contador\(4) & ((!\Contador8|Contador\(7))))) # (!\Contador8|Contador\(5) & ((\Contador8|Contador\(6) & ((!\Contador8|Contador\(7)))) # (!\Contador8|Contador\(6) & 
-- (\Contador8|Contador\(4)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000001010101110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(6),
	datac => \Contador8|Contador\(5),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux4~0_combout\);

-- Location: LCCOMB_X54_Y72_N8
\Digito2|Mux3~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux3~0_combout\ = (\Contador8|Contador\(5) & ((\Contador8|Contador\(4) & (\Contador8|Contador\(6))) # (!\Contador8|Contador\(4) & (!\Contador8|Contador\(6) & \Contador8|Contador\(7))))) # (!\Contador8|Contador\(5) & (!\Contador8|Contador\(7) & 
-- (\Contador8|Contador\(4) $ (\Contador8|Contador\(6)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001000010000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(6),
	datac => \Contador8|Contador\(5),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux3~0_combout\);

-- Location: LCCOMB_X54_Y72_N30
\Digito2|Mux2~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux2~0_combout\ = (\Contador8|Contador\(6) & (\Contador8|Contador\(7) & ((\Contador8|Contador\(5)) # (!\Contador8|Contador\(4))))) # (!\Contador8|Contador\(6) & (!\Contador8|Contador\(4) & (\Contador8|Contador\(5) & !\Contador8|Contador\(7))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100010000010000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(6),
	datac => \Contador8|Contador\(5),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux2~0_combout\);

-- Location: LCCOMB_X54_Y72_N12
\Digito2|Mux1~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux1~0_combout\ = (\Contador8|Contador\(5) & ((\Contador8|Contador\(4) & ((\Contador8|Contador\(7)))) # (!\Contador8|Contador\(4) & (\Contador8|Contador\(6))))) # (!\Contador8|Contador\(5) & (\Contador8|Contador\(6) & (\Contador8|Contador\(4) $ 
-- (\Contador8|Contador\(7)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110010001001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(6),
	datac => \Contador8|Contador\(5),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux1~0_combout\);

-- Location: LCCOMB_X54_Y72_N6
\Digito2|Mux0~0\ : cycloneive_lcell_comb
-- Equation(s):
-- \Digito2|Mux0~0_combout\ = (\Contador8|Contador\(6) & (!\Contador8|Contador\(5) & (\Contador8|Contador\(4) $ (!\Contador8|Contador\(7))))) # (!\Contador8|Contador\(6) & (\Contador8|Contador\(4) & (\Contador8|Contador\(5) $ (!\Contador8|Contador\(7)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0010100000000110",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \Contador8|Contador\(4),
	datab => \Contador8|Contador\(6),
	datac => \Contador8|Contador\(5),
	datad => \Contador8|Contador\(7),
	combout => \Digito2|Mux0~0_combout\);

ww_SegDigit1(6) <= \SegDigit1[6]~output_o\;

ww_SegDigit1(5) <= \SegDigit1[5]~output_o\;

ww_SegDigit1(4) <= \SegDigit1[4]~output_o\;

ww_SegDigit1(3) <= \SegDigit1[3]~output_o\;

ww_SegDigit1(2) <= \SegDigit1[2]~output_o\;

ww_SegDigit1(1) <= \SegDigit1[1]~output_o\;

ww_SegDigit1(0) <= \SegDigit1[0]~output_o\;

ww_SegDigit2(6) <= \SegDigit2[6]~output_o\;

ww_SegDigit2(5) <= \SegDigit2[5]~output_o\;

ww_SegDigit2(4) <= \SegDigit2[4]~output_o\;

ww_SegDigit2(3) <= \SegDigit2[3]~output_o\;

ww_SegDigit2(2) <= \SegDigit2[2]~output_o\;

ww_SegDigit2(1) <= \SegDigit2[1]~output_o\;

ww_SegDigit2(0) <= \SegDigit2[0]~output_o\;
END structure;


