

-- Descripción de una procesador que ejecuta cuatro instrucciones. 
-- Basado en ejemplo de Hamblen, J.O., Hall T.S., Furman, M.D.:
-- Rapid Prototyping of Digital Systems : SOPC Edition, Springer 2008.
-- (Capítulo 9) 

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY procesador_v2_4 IS
    PORT (
        clock : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        SW_IN : IN STD_LOGIC_VECTOR(7 DOWNTO 0); -- IN (6.4)
        AC_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- Accumulator
        IR_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- Instruction Register
        PC_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); -- Program Counter
        LEDG_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); -- OUT (6.4)
        MEMq : IN STD_LOGIC_VECTOR(15 DOWNTO 0); -- Mem out (queue)
        MEMdata : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- 
        MEMwe : OUT STD_LOGIC; -- Mem write enable
        MEMadr : OUT STD_LOGIC_VECTOR(7 DOWNTO 0) -- Mem address
    );
END procesador_v2_4;

ARCHITECTURE rtl OF procesador_v2_4 IS
    TYPE STATE_TYPE IS (
        reset_pc,
        fetch1,
        decode,
        load1,
        store0, store1,
        add1, add2,
        jump,
        sub1, sub2, -- 6.1
        nand1, nand2, -- 6.1
        jneg, jpos, jzero, -- 6.2
        shiftl1, shiftr1, -- 6.3
        io_in, io_out -- 6.4
    );
    SIGNAL state : STATE_TYPE;
    SIGNAL IR, AC, TEMP : STD_LOGIC_VECTOR(15 DOWNTO 0);
    SIGNAL PC : STD_LOGIC_VECTOR(7 DOWNTO 0);
    SIGNAL LEDG : STD_LOGIC_VECTOR(7 DOWNTO 0);

BEGIN
    -- Asignaciones a puertos de salida
    --	
    AC_out <= AC;
    IR_out <= IR;
    PC_out <= PC;
    LEDG_out <= LEDG;
    FSMD : PROCESS (CLOCK, RESET, state, PC, AC, IR, LEDG) -- Finite State Machine with Data (¿something?)

    BEGIN

        -- Asignaciones a REGISTROS en datapath y MAQUINA DE ESTADOS de la unidad de control
        IF reset = '1' THEN
            state <= reset_pc;
        ELSIF clock'EVENT AND clock = '1' THEN
            CASE state IS
                WHEN reset_pc => -- Ordenamos a resettear cuando aparezca el siguiente flanco
                    PC <= "00000000";
                    AC <= "0000000000000000";
                    state <= fetch1;
                WHEN fetch1 =>
                    IR <= MEMq;
                    PC <= PC + 1;
                    state <= decode;
                WHEN decode =>
                    CASE IR(15 DOWNTO 8) IS
                        WHEN "00000000" =>
                            state <= add1;
                        WHEN "00000001" =>
                            state <= store0;
                        WHEN "00000010" =>
                            state <= load1;
                        WHEN "00000011" =>
                            state <= jump;
                        WHEN "00000100" =>
                            state <= sub1;
                        WHEN "00000101" =>
                            state <= nand1;
                        WHEN "00000110" =>
                            state <= jneg;
                        WHEN "00000111" =>
                            state <= jpos;
                        WHEN "00001000" =>
                            state <= jzero;
                        WHEN "00001001" =>
                            state <= shiftl1;
                        WHEN "00001010" =>
                            state <= shiftr1;
                        WHEN "00001011" =>
                            state <= io_in;
                        WHEN "00001100" =>
                            state <= io_out;
                        WHEN OTHERS =>
                            state <= fetch1;
                    END CASE;
                WHEN add1 =>
                    TEMP <= MEMq;
                    state <= add2;
                WHEN add2 =>
                    AC <= AC + TEMP;
                    state <= fetch1;
                WHEN store0 =>
                    state <= store1;
                WHEN store1 =>
                    state <= fetch1;
                WHEN load1 =>
                    AC <= MEMq;
                    state <= fetch1;
                WHEN jump =>
                    PC <= IR(7 DOWNTO 0);
                    state <= fetch1;
                WHEN sub1 =>
                    TEMP <= MEMq;
                    state <= sub2;
                WHEN sub2 =>
                    AC <= AC - TEMP;
                    state <= fetch1;
                WHEN nand1 =>
                    TEMP <= MEMq;
                    state <= nand2;
                WHEN nand2 =>
                    AC <= AC NAND TEMP;
                    state <= fetch1;
                WHEN jneg =>
                    IF AC(15) = '1' THEN
                        PC <= IR(7 DOWNTO 0);
                    END IF;
                    state <= fetch1;
                WHEN jpos =>
                    IF AC > 0 AND AC(15) = '0' THEN
                        PC <= IR(7 DOWNTO 0);
                    END IF;
                    state <= fetch1;
                WHEN jzero =>
                    IF AC = 0 THEN
                        PC <= IR(7 DOWNTO 0);
                    END IF;
                    state <= fetch1;
                WHEN shiftl1 =>
                    AC <= SHL(AC, IR(7 DOWNTO 0));
                    state <= fetch1;
                WHEN shiftr1 =>
                    AC <= SHR(AC, IR(7 DOWNTO 0));
                    state <= fetch1;
                WHEN io_in =>
                    IF IR(0) = '0' THEN
                        AC(7 DOWNTO 0) <= SW_IN(7 DOWNTO 0);
                    ELSE
                        AC(15 DOWNTO 8) <= SW_IN(7 DOWNTO 0);
                    END IF;
                    state <= fetch1;
                WHEN io_out =>
                    IF IR(0) = '0' THEN
                        LEDG(7 DOWNTO 0) <= AC(7 DOWNTO 0);
                    ELSE
                        LEDG(7 DOWNTO 0) <= AC(15 DOWNTO 8);
                    END IF;
                    state <= fetch1;
                WHEN OTHERS =>
                    state <= fetch1;
            END CASE;
        END IF;

        -- Asignaciones a BUSES de entrada a MEMORIA (Direcciones, Datos y control de escritura)

        CASE state IS
            WHEN reset_pc =>
                MEMadr <= (OTHERS => '0');
                MEMwe <= '0';
                MEMdata <= (OTHERS => '-');
            WHEN fetch1 | decode | add1 | sub1 | nand1 | jump =>
                MEMadr <= IR(7 DOWNTO 0);
                MEMwe <= '0';
                MEMdata <= (OTHERS => '-');
            WHEN store0 =>
                MEMadr <= IR(7 DOWNTO 0);
                MEMwe <= '1';
                MEMdata <= AC;
            WHEN jneg =>
                IF AC(15) = '1' THEN
                    MEMadr <= IR(7 DOWNTO 0);
                    MEMwe <= '0';
                    MEMdata <= (OTHERS => '-');
                ELSE
                    MEMadr <= PC;
                    MEMwe <= '0';
                    MEMdata <= (OTHERS => '-');
                END IF;
            WHEN jpos =>
                IF AC > 0 AND AC(15) = '0' THEN
                    MEMadr <= IR(7 DOWNTO 0);
                    MEMwe <= '0';
                    MEMdata <= (OTHERS => '-');
                ELSE
                    MEMadr <= PC;
                    MEMwe <= '0';
                    MEMdata <= (OTHERS => '-');
                END IF;
            WHEN jzero =>
                IF AC = 0 THEN
                    MEMadr <= IR(7 DOWNTO 0);
                    MEMwe <= '0';
                    MEMdata <= (OTHERS => '-');
                ELSE
                    MEMadr <= PC;
                    MEMwe <= '0';
                    MEMdata <= (OTHERS => '-');
                END IF;
            WHEN OTHERS =>
                MEMadr <= PC;
                MEMwe <= '0';
                MEMdata <= (OTHERS => '-');
        END CASE;

    END PROCESS;
END rtl;