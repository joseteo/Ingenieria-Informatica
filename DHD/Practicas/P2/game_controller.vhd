LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;
LIBRARY lpm;
USE lpm.lpm_components.ALL;

ENTITY game_controller IS
    GENERIC (
        Pala1_Init_X : NATURAL := 629;
        Pala2_Init_X : NATURAL := 10;
        Bola_Init_Speed : NATURAL := 2;
        Bola_Incr_Speed : NATURAL := 1;
        Sep_Size : NATURAL := 1
    );
    PORT (
        Red, Green, Blue : OUT STD_LOGIC;
        vs : IN STD_LOGIC;
        pixel_Y, pixel_X : IN STD_LOGIC_VECTOR(9 DOWNTO 0);
        BT1_UP, BT1_DOWN : IN STD_LOGIC;
        BT2_UP, BT2_DOWN : IN STD_LOGIC;
        LED1_SCORE, LED2_SCORE : OUT STD_LOGIC_VECTOR(0 TO 13)
    );
END game_controller;

ARCHITECTURE funcional OF game_controller IS
    TYPE STATE_TYPE IS (waiting, ready, change);

    -- Bola
    SIGNAL Bola_on : STD_LOGIC;
    SIGNAL Bola_Desplaza_Y : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(Bola_Init_Speed, 10);
    SIGNAL Bola_Desplaza_X : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(Bola_Init_Speed, 10); -- 2.3
    SIGNAL Bola_Y : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(240, 10);
    SIGNAL Bola_X : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(320, 10); -- 2.3

    CONSTANT Bola_Size : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(8, 10);

    -- Pala 1
    SIGNAL Pala1_on : STD_LOGIC;
    SIGNAL Pala1_Desplaza_Y : STD_LOGIC_VECTOR(9 DOWNTO 0);
    SIGNAL Pala1_Y : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(240, 10);
    SIGNAL Pala1_Score : STD_LOGIC_VECTOR(7 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(0, 8); -- TODO: Revisar el verdadero tamaño en bits
	 SIGNAL Pared1_Colision : STATE_TYPE := waiting;

    CONSTANT Pala1_X : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(Pala1_Init_X, 10);

    -- Pala 2
    SIGNAL Pala2_on : STD_LOGIC;
    SIGNAL Pala2_Desplaza_Y : STD_LOGIC_VECTOR(9 DOWNTO 0);
    SIGNAL Pala2_Y : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(240, 10);
    SIGNAL Pala2_Score : STD_LOGIC_VECTOR(7 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(0, 8); -- TODO: Revisar el verdadero tamaño en bits
	 SIGNAL Pared2_Colision : STATE_TYPE := waiting;

    CONSTANT Pala2_X : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(Pala2_Init_X, 10);

    -- Palas en general
    CONSTANT Pala_Size_Y : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(60, 10);
    CONSTANT Pala_Size_X : STD_LOGIC_VECTOR(9 DOWNTO 0) := CONV_STD_LOGIC_VECTOR(8, 10);

    -- Separador
    SIGNAL Sep_On : STD_LOGIC;

    FUNCTION IntToHex(IntValue : IN STD_LOGIC_VECTOR(7 DOWNTO 0)) RETURN STD_LOGIC_VECTOR IS
        VARIABLE seg_digit : STD_LOGIC_VECTOR(0 TO 13) := "00000000000000";
        VARIABLE incr : STD_LOGIC_VECTOR(3 DOWNTO 0) := "0000";
    BEGIN
        CASE IntValue(3 DOWNTO 0) IS
            WHEN "0000" =>
                seg_digit(7 TO 13) := "0000001";
            WHEN "0001" =>
                seg_digit(7 TO 13) := "1001111";
            WHEN "0010" =>
                seg_digit(7 TO 13) := "0010010";
            WHEN "0011" =>
                seg_digit(7 TO 13) := "0000110";
            WHEN "0100" =>
                seg_digit(7 TO 13) := "1001100";
            WHEN "0101" =>
                seg_digit(7 TO 13) := "0100100";
            WHEN "0110" =>
                seg_digit(7 TO 13) := "0100000";
            WHEN "0111" =>
                seg_digit(7 TO 13) := "0001111";
            WHEN "1000" =>
                seg_digit(7 TO 13) := "0000000";
            WHEN "1001" =>
                seg_digit(7 TO 13) := "0000100";
            WHEN "1010" => -- a
                seg_digit(7 TO 13) := "0000001";
                -- seg_digit(6 DOWNTO 0) := "0001000";
                incr := "0001";
            WHEN "1011" => -- b
                seg_digit(7 TO 13) := "1001111";
                -- seg_digit(6 DOWNTO 0) := "1100000";
                incr := "0001";
            WHEN "1100" => --c
                seg_digit(7 TO 13) := "0010010";
                -- seg_digit(6 DOWNTO 0) := "0110001";
                incr := "0001";
            WHEN "1101" => --d
                seg_digit(7 TO 13) := "0000110";
                -- seg_digit(6 DOWNTO 0) := "1000010";
                incr := "0001";
            WHEN "1110" => --e
                seg_digit(7 TO 13) := "1001100";
                -- seg_digit(6 DOWNTO 0) := "0110000";
                incr := "0001";
            WHEN OTHERS => --f
                seg_digit(7 TO 13) := "1001100";
                -- seg_digit(6 DOWNTO 0) := "0111000";
                incr := "0001";
        END CASE;
        CASE (IntValue(7 DOWNTO 4) + INCR) IS
            WHEN "0000" =>
                seg_digit(0 TO 6) := "0000001";
            WHEN "0001" =>
                seg_digit(0 TO 6) := "1001111";
            WHEN "0010" =>
                seg_digit(0 TO 6) := "0010010";
            WHEN "0011" =>
                seg_digit(0 TO 6) := "0000110";
            WHEN "0100" =>
                seg_digit(0 TO 6) := "1001100";
            WHEN "0101" =>
                seg_digit(0 TO 6) := "0100100";
            WHEN "0110" =>
                seg_digit(0 TO 6) := "0100000";
            WHEN "0111" =>
                seg_digit(0 TO 6) := "0001111";
            WHEN "1000" =>
                seg_digit(0 TO 6) := "0000000";
            WHEN "1001" =>
                seg_digit(0 TO 6) := "0000100";
            WHEN "1010" => -- a
                seg_digit(0 TO 6) := "0001000";
            WHEN "1011" => -- b
                seg_digit(0 TO 6) := "1100000";
            WHEN "1100" => --c
                seg_digit(0 TO 6) := "0110001";
            WHEN "1101" => --d
                seg_digit(0 TO 6) := "1000010";
            WHEN "1110" => --e
                seg_digit(0 TO 6) := "0110000";
            WHEN OTHERS => --f
                seg_digit(0 TO 6) := "0111000";
        END CASE;
        RETURN seg_digit;
    END FUNCTION;

BEGIN
    ---------------------- Señales de salida ----------------------
    Red <= Bola_on OR Pala1_on OR Pala2_on;
    Green <= Bola_on OR Pala1_on OR Sep_on;
    Blue <= Bola_on OR Pala2_on OR Sep_on;

    LED1_SCORE <= IntToHex(Pala1_Score);
    LED2_SCORE <= IntToHex(Pala2_Score);
    ---------------------- Procesos ----------------------
    Dibujar_Separador : PROCESS (pixel_X, pixel_Y)
    BEGIN
        -- Linea separadora de la mitad
        IF ((pixel_X < CONV_STD_LOGIC_VECTOR(320, 10) + Sep_Size)
            AND (pixel_X + Sep_Size > CONV_STD_LOGIC_VECTOR(320, 10))) THEN
            Sep_on <= '1';
        ELSE
            Sep_on <= '0';
        END IF;
    END PROCESS Dibujar_Separador;

    ---------- Bola ----------
    Dibujar_Bola : PROCESS (Bola_Y, Bola_X, pixel_X, pixel_Y) -- 2.3
    BEGIN
        -- Chequear coordenadas X e Y para identificar el area de la bola
        -- Poner Bola_on a '1' para visualizar la bola
        IF (Bola_X <= pixel_X + Bola_Size) AND (Bola_X + Bola_Size >= pixel_X) AND
            (Bola_Y <= pixel_Y + Bola_Size) AND (Bola_Y + Bola_Size >= pixel_Y) THEN
            Bola_on <= '1';
        ELSE
            Bola_on <= '0';
        END IF;
    END PROCESS Dibujar_Bola;

    Mover_Bola : PROCESS (vs) -- TODO: Añadir rebote
    BEGIN
        -- Actualizar la posicion de la bola en cada refresco de pantalla
        IF vs'event AND vs = '1' THEN
            -- Detectar los bordes superior e inferior de la pantalla
            IF Bola_Y + Bola_Size >= CONV_STD_LOGIC_VECTOR(479, 10) THEN
                Bola_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(-Bola_Init_Speed, 10);
            ELSIF Bola_Y <= Bola_Size THEN
                Bola_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(Bola_Init_Speed, 10);
            ELSE
                Bola_Desplaza_Y <= Bola_Desplaza_Y;
            END IF;

            -- Detectar la pala izquierda
            -- TODO: Debe detectar esto antes que lo siguiente para asegurarnos de que rebote correctamente
            -- TODO: Cada rebote con una pala aumenta la velocidad
				IF (Bola_X + Bola_Size + Pala_Size_X >= Pala1_X) AND
					(Bola_Y + Pala_Size_Y > Pala1_Y) AND
					(Bola_Y < Pala1_Y + Pala_Size_Y)
					THEN
						Bola_Desplaza_X <= CONV_STD_LOGIC_VECTOR(CONV_SIGNED(-Bola_Incr_Speed, 10) + CONV_SIGNED(CONV_INTEGER(Bola_Desplaza_X), 10), 10);
				END IF;
	
            -- Detectar la pala derecha
            -- TODO: Debe detectar esto antes que lo siguiente para asegurarnos de que rebote correctamente
            -- TODO: Cada rebote con una pala aumenta la velocidad
				IF (Bola_X <= Pala2_X + Pala_Size_X + Bola_Size) AND
					(Bola_Y + Pala_Size_Y > Pala2_Y) AND
					(Bola_Y < Pala2_Y + Pala_Size_Y)
						THEN
							Bola_Desplaza_X <= CONV_STD_LOGIC_VECTOR(CONV_SIGNED(Bola_Incr_Speed, 10) + CONV_SIGNED(CONV_INTEGER(Bola_Desplaza_X), 10), 10);
				END IF;

            -- Detectar los bordes izquierda y derecha de la pantalla
            CASE Pared2_Colision IS
                WHEN waiting =>
						  IF Bola_X + Bola_Size >= CONV_STD_LOGIC_VECTOR(639, 10) THEN -- Ha chocado con el borde derecho
                        Pared2_Colision <= ready;
								Bola_Desplaza_X <= CONV_STD_LOGIC_VECTOR(-Bola_Init_Speed, 10);
                    ELSE
                        Pared2_Colision <= waiting;
                    END IF;
                WHEN ready =>
                    IF not(Bola_X + Bola_Size >= CONV_STD_LOGIC_VECTOR(639, 10)) THEN
                        Pared2_Colision <= change;
                    ELSE
                        Pared2_Colision <= ready;
                    END IF;
                WHEN change =>
						  Pala2_Score <= Pala2_Score + CONV_STD_LOGIC_VECTOR(1, 8);
                    Pared2_Colision <= waiting;
            END CASE;
				
				-- Detectar los bordes izquierda y derecha de la pantalla
            CASE Pared1_Colision IS
                WHEN waiting =>
						  IF Bola_X <= Bola_Size THEN -- Ha chocado con el borde izquierdo
                        Pared1_Colision <= ready;
								Bola_Desplaza_X <= CONV_STD_LOGIC_VECTOR(Bola_Init_Speed, 10);
                    ELSE
                        Pared1_Colision <= waiting;
                    END IF;
                WHEN ready =>
                    IF not(Bola_X <= Bola_Size) THEN -- Ha chocado con el borde izquierdo
                        Pared1_Colision <= change;
                    ELSE
                        Pared1_Colision <= ready;
                    END IF;
                WHEN change =>
						  Pala1_Score <= Pala1_Score + CONV_STD_LOGIC_VECTOR(1, 8);
                    Pared1_Colision <= waiting;
            END CASE;

            -- Calcular la siguiente posicion de la bola
            Bola_Y <= Bola_Y + Bola_Desplaza_Y;
            Bola_X <= Bola_X + Bola_Desplaza_X;
        END IF;
    END PROCESS Mover_Bola;

    -- Palas:
    Dibujar_Palas : PROCESS (Pala1_Y, Pala2_Y, pixel_X, pixel_Y) -- 2.3
    BEGIN
        -- Poner Pala1_on a '1' para visualizar la pala1
        -- Chequear coordenadas X e Y para identificar el area de la pala
        IF (Pala1_X <= pixel_X + Pala_Size_X) AND (Pala1_X + Pala_Size_X >= pixel_X) AND
            (Pala1_Y <= pixel_Y + Pala_Size_Y) AND (Pala1_Y + Pala_Size_Y >= pixel_Y) THEN
            Pala1_on <= '1';
        ELSE
            Pala1_on <= '0';
        END IF;

        -- Poner Pala2_on a '1' para visualizar la pala2
        -- Chequear coordenadas X e Y para identificar el area de la pala
        IF (Pala2_X <= pixel_X + Pala_Size_X) AND (Pala2_X + Pala_Size_X >= pixel_X) AND
            (Pala2_Y <= pixel_Y + Pala_Size_Y) AND (Pala2_Y + Pala_Size_Y >= pixel_Y) THEN
            Pala2_on <= '1';
        ELSE
            Pala2_on <= '0';
        END IF;
    END PROCESS Dibujar_Palas;

    Mover_Palas : PROCESS (vs)
    BEGIN
        -- Actualizar la posicion de la pala en cada refresco de pantalla
        IF vs'event AND vs = '1' THEN
            -- Detectar los bordes superior e inferior de la pantalla
            IF BT2_UP = '0' AND BT2_DOWN = '0' THEN
                Pala1_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(0, 10);
            ELSIF BT2_UP = '0' AND Pala1_Y > Pala_Size_Y THEN
                Pala1_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(-2, 10);
            ELSIF BT2_DOWN = '0' AND Pala1_Y < CONV_STD_LOGIC_VECTOR(479, 10) - Pala_Size_Y THEN
                Pala1_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(2, 10);
            ELSE
                Pala1_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(0, 10);
            END IF;

            -- Detectar los bordes superior e inferior de la pantalla
            IF BT1_UP = '0' AND BT1_DOWN = '0' THEN
                Pala1_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(0, 10);
            ELSIF BT1_UP = '0' AND Pala2_Y > Pala_Size_Y THEN
                Pala2_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(-2, 10);
            ELSIF BT1_DOWN = '0' AND Pala2_Y < CONV_STD_LOGIC_VECTOR(479, 10) - Pala_Size_Y THEN
                Pala2_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(2, 10);
            ELSE
                Pala2_Desplaza_Y <= CONV_STD_LOGIC_VECTOR(0, 10);
            END IF;

            -- Calcular la siguiente posicion de la pala
            Pala1_Y <= Pala1_Y + Pala1_Desplaza_Y;
            Pala2_Y <= Pala2_Y + Pala2_Desplaza_Y;
        END IF;
    END PROCESS Mover_Palas;

END funcional;