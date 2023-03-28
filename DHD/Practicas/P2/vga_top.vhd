-- Descripcion que visualiza franjas de colores en un monitor VGA
--
-- Basado en ejemplo de Hamblen, J.O., Hall T.S., Furman, M.D.:
-- Rapid Prototyping of Digital Systems : SOPC Edition, Springer 2008.
-- (Capitulo 10)
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

LIBRARY lpm;
USE lpm.lpm_components.ALL;
ENTITY vga_top IS

    PORT (
        CLOCK_50 : IN STD_LOGIC;
        VGA_R : OUT STD_LOGIC_VECTOR(0 TO 7);
        VGA_G : OUT STD_LOGIC_VECTOR(0 TO 7);
        VGA_B : OUT STD_LOGIC_VECTOR(0 TO 7);
        VGA_BLANK_N : OUT STD_LOGIC;
        VGA_HS : OUT STD_LOGIC;
        VGA_VS : OUT STD_LOGIC;
        VGA_CLK : OUT STD_LOGIC;
        BT1_UP, BT1_DOWN, BT2_UP, BT2_DOWN : IN STD_LOGIC; -- 2.4
		  LED1_SCORE, LED2_SCORE: OUT STD_LOGIC_VECTOR(0 to 13)
    );

END vga_top;

ARCHITECTURE funcional OF vga_top IS

    -- Componente del PLL (50MHz -> 25MHz)
    COMPONENT vga_PLL
        PORT (
            inclk0 : IN STD_LOGIC := '0';
            c0 : OUT STD_LOGIC);
    END COMPONENT;

    -- Componente del controlador VGA
    COMPONENT controlador_vga_640_x_480_60
        PORT (
            clock_25 : IN STD_LOGIC;
            R, G, B : IN STD_LOGIC;
            VGA_R, VGA_G, VGA_B : OUT STD_LOGIC;
            vga_blank_N : OUT STD_LOGIC;
            vga_hs : OUT STD_LOGIC;
            vga_vs : OUT STD_LOGIC;
            vga_clk : OUT STD_LOGIC;
            pixel_y : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);
            pixel_x : OUT STD_LOGIC_VECTOR(9 DOWNTO 0));
    END COMPONENT;

    -- Componente del controlador del juego
    COMPONENT game_controller
        GENERIC (
            Pala1_Init_X : NATURAL := 629;
            Pala2_Init_X : NATURAL := 10;
				Bola_Incr_Speed : Natural := 1
        );
        PORT (
            Red, Green, Blue : OUT STD_LOGIC;
            vs : IN STD_LOGIC;
            pixel_Y, pixel_X : IN STD_LOGIC_VECTOR(9 DOWNTO 0);
            BT1_UP, BT1_DOWN : IN STD_LOGIC;
            BT2_UP, BT2_DOWN : IN STD_LOGIC;
				LED1_SCORE, LED2_SCORE: OUT STD_LOGIC_VECTOR(0 to 13)
        );
    END COMPONENT;

    -- Señales internas
    SIGNAL clock_25 : STD_LOGIC;
    SIGNAL pixel_x, pixel_y : STD_LOGIC_VECTOR(9 DOWNTO 0);
    SIGNAL VGA_VS_OUT : STD_LOGIC;
    SIGNAL R_Data, G_Data, B_Data : STD_LOGIC;

BEGIN

    VGA_VS <= VGA_VS_OUT;

    -- PLL para generar el reloj de 25 MHz
    PLL : vga_pll PORT MAP(
        inclk0 => clock_50,
        c0 => clock_25);

    -- Controlador de la VGA
    VGA : controlador_vga_640_x_480_60 PORT MAP(
        clock_25 => clock_25,
        R => R_data,
        g => G_data,
        b => B_data,
        vga_r => vga_R(7),
        vga_g => vga_g(7),
        vga_b => vga_b(7),
        vga_blank_n => vga_blank_n,
        vga_hs => vga_hs,
        vga_vs => VGA_VS_OUT,
        vga_clk => vga_clk,
        pixel_y => pixel_y,
        pixel_x => pixel_x);

    -- Instancia del controlador de juego
    Controller : game_controller
    GENERIC MAP(
        Pala1_Init_X => 619,
        Pala2_Init_X => 20,
		  Bola_Incr_Speed => 1)
    PORT MAP(
        Red => R_data,
        Green => G_data,
        Blue => B_data,
        vs => VGA_VS_OUT,
        pixel_Y => pixel_y,
        pixel_X => pixel_x,
        BT1_UP => BT1_UP,
        BT1_DOWN => BT1_DOWN,
        BT2_UP => BT2_UP,
        BT2_DOWN => BT2_DOWN,
		  LED1_SCORE => LED1_SCORE,
		  LED2_SCORE => LED2_SCORE
    );

END funcional;