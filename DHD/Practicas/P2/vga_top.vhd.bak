
-- Descripci�n que visualiza franjas de colores en un monitor VGA
--
-- Basado en ejemplo de Hamblen, J.O., Hall T.S., Furman, M.D.:
-- Rapid Prototyping of Digital Systems : SOPC Edition, Springer 2008.
-- (Cap�tulo 10) 


LIBRARY IEEE;
USE  IEEE.STD_LOGIC_1164.all;
USE IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

LIBRARY lpm;
USE lpm.lpm_components.ALL;


ENTITY vga_top IS

PORT(	
      CLOCK_50			     : IN STD_LOGIC;
		VGA_R		: OUT STD_LOGIC_vector(0 to 7);
		VGA_G		: OUT STD_LOGIC_vector(0 to 7);
		VGA_B		: OUT STD_LOGIC_vector(0 to 7);
		VGA_BLANK_N		: OUT STD_LOGIC;
		VGA_HS		: OUT STD_LOGIC;
		VGA_VS		: OUT STD_LOGIC;
		VGA_CLK		: OUT STD_LOGIC
		);

END vga_top;

ARCHITECTURE funcional OF vga_top IS


	COMPONENT vga_PLL
		PORT(
			inclk0		: IN STD_LOGIC  := '0';
			c0		: OUT STD_LOGIC );
	END COMPONENT;
	
	COMPONENT controlador_vga_640_x_480_60
		PORT(	
			clock_25		: 	IN	STD_LOGIC;
			R,G,B       : 	     IN	     STD_LOGIC;
			VGA_R, VGA_G, VGA_B		:	OUT	STD_LOGIC;
			vga_blank_N	:	OUT	STD_LOGIC;
			vga_hs		:	OUT     STD_LOGIC;
			vga_vs		:	OUT     STD_LOGIC;
			vga_clk		:	OUT     STD_LOGIC;
			pixel_y		:	OUT     STD_LOGIC_VECTOR(9 DOWNTO 0);
			pixel_x		:	OUT	STD_LOGIC_VECTOR(9 DOWNTO 0));		
	END COMPONENT;
	


SIGNAL clock_25 : STD_LOGIC;
SIGNAL R_Data, G_Data, B_Data : STD_LOGIC;
SIGNAL pixel_x, pixel_y	: STD_LOGIC_VECTOR(9 DOWNTO 0);



BEGIN

R_data  <= pixel_y(7);
G_data  <= pixel_y(6);
B_data  <= pixel_y(5);


	-- PLL para generar el reloj de 25 MHz
PLL: vga_pll PORT MAP (
		inclk0 => clock_50,
		c0 => clock_25);
		

	-- Controlador de la VGA
VGA:  controlador_vga_640_x_480_60 PORT MAP (	
		clock_25	=> clock_25,
		R => R_data,
		g => G_data,
		b => B_data,	
		vga_r	=> vga_R(7),
		vga_g => vga_g(7),
		vga_b => vga_b(7),
		vga_blank_n => vga_blank_n,
		vga_hs => vga_hs, 
		vga_vs => vga_vs, 
		vga_clk	=> vga_clk,
		pixel_y => pixel_y, 
		pixel_x => pixel_x);		
			
			 	

END funcional;

