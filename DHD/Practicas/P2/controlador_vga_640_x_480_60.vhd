LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY controlador_vga_640_x_480_60 IS
    PORT (
        clock_25 : IN STD_LOGIC;
        r, g, b : IN STD_LOGIC;
        vga_r : OUT STD_LOGIC;
        vga_g : OUT STD_LOGIC;
        vga_b : OUT STD_LOGIC;
        vga_blank_N : OUT STD_LOGIC;
        vga_hs : OUT STD_LOGIC;
        vga_vs : OUT STD_LOGIC;
        vga_clk : OUT STD_LOGIC;
        pixel_y : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);
        pixel_x : OUT STD_LOGIC_VECTOR(9 DOWNTO 0)
    );

END controlador_vga_640_x_480_60;

ARCHITECTURE rtl OF controlador_vga_640_x_480_60 IS

    -- Especificacione temporales VGA 640 x 480 pixels (60 Hz), 25M pixels/s
    -- Sincronización horizontal (en número de pixels/línea)
    CONSTANT h_a : INTEGER := 96; -- Retorno horizontal
    CONSTANT h_b : INTEGER := 48; -- "Back porch" horizontal (Margen izquierdo)
    CONSTANT h_c : INTEGER := 640; -- Área de visualización horizontal 
    CONSTANT h_d : INTEGER := 16; -- "Front porch" horizontal (Margen derecho)  
    CONSTANT h_total : INTEGER := h_a + h_b + h_c + h_d;

    -- Sincronización Vertical (en número de líneas/pantalla)  
    CONSTANT v_a : INTEGER := 2; -- Retorno vertical
    CONSTANT v_b : INTEGER := 33; -- "Back porch" vertical
    CONSTANT v_c : INTEGER := 480; -- Área de visualización vertical 
    CONSTANT v_d : INTEGER := 10; -- "Front porch" vertical 
    CONSTANT v_total : INTEGER := v_a + v_b + v_c + v_d;
    SIGNAL hs, vs : STD_LOGIC;
    SIGNAL video_on : STD_LOGIC;
    SIGNAL cont_hs, cont_vs : STD_LOGIC_VECTOR(9 DOWNTO 0);

BEGIN

    -- La señal vga_clk que va al DAC coincide con el reloj de 25MHz. 
    vga_clk <= clock_25;

    PROCESS
    BEGIN
        WAIT UNTIL(clock_25'EVENT) AND (clock_25 = '1');
        -- Se generan las señales de sinronizacion horizontal y vertical
        -- a partir de los contadores cont_hs y cont_vs

        -- El contador cont_hs cuenta los pixels/fila
        -- La señal de sincronización horizontal (hs) vale cero durante el retorno horizontal 

        --
        IF (cont_hs = h_total - 1) THEN
            cont_hs <= "0000000000";
        ELSE
            cont_hs <= cont_hs + 1;
        END IF;

        IF (cont_hs <= h_c + h_d + h_a - 1) AND (cont_hs >= h_c + h_d) THEN
            hs <= '0';
        ELSE
            hs <= '1';
        END IF;

        -- El contador cont_vs cuenta las filas/pantalla
        -- La señal de sincronización vertical (vs) vale cero durante el retorno vertical

        IF (cont_vs = v_total - 1) AND (cont_hs >= h_total - h_a - h_d) THEN
            cont_vs <= "0000000000";
        ELSIF (cont_hs = h_total - h_a - h_d) THEN
            cont_vs <= cont_vs + 1;
        END IF;

        IF (cont_vs <= v_c + v_d + v_a - 1) AND (cont_vs >= v_c + v_d) THEN
            vs <= '0';
        ELSE
            vs <= '1';
        END IF;
        -- Se generan señales para informar a la salida de la coordenada de pixel a visualizar
        IF (cont_hs <= 639) THEN
            pixel_x <= cont_hs;
        END IF;
        IF (cont_vs <= 479) THEN
            pixel_y <= cont_vs;
        END IF;

        -- La señal video_on está en alta cuando se transmite información de video
        -- (para valores de cont_vs entre 0 y 479, y valores de cont_hs entre 0 y 639)

        IF (cont_hs <= 639) AND (cont_vs <= 479) THEN
            video_on <= '1';
        ELSE
            video_on <= '0';
        END IF;

        -- Se registran todas las señales de video para eliminar retardos que puedan emborronar la imagen
        vga_r <= r AND video_on;
        vga_g <= g AND video_on;
        vga_b <= b AND video_on;
        vga_hs <= hs;
        vga_vs <= vs;
        vga_blank_n <= video_on;

    END PROCESS;

END rtl;