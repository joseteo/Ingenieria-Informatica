

-- Descripción de una procesador que ejecuta cuatro instrucciones. 
-- Basado en ejemplo de Hamblen, J.O., Hall T.S., Furman, M.D.:
-- Rapid Prototyping of Digital Systems : SOPC Edition, Springer 2008.
-- (Capítulo 9) 

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY procesador_v0_0 IS
    PORT (
        clock : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        AC_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- Accumulator
        IR_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- Instruction Register
        PC_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); -- Program Counter
        MEMq : IN STD_LOGIC_VECTOR(15 DOWNTO 0); -- Mem out (queue)
        MEMdata : OUT STD_LOGIC_VECTOR(15 DOWNTO 0); -- 
        MEMwe : OUT STD_LOGIC; -- Mem write enable
        MEMadr : OUT STD_LOGIC_VECTOR(7 DOWNTO 0) -- Mem address
    );
END procesador_v0_0;

ARCHITECTURE rtl OF procesador_v0_0 IS
    TYPE STATE_TYPE IS (reset_pc, fetch0, fetch1, decode, add0, add1, load0, load1,
        store0, store1, jump);
    SIGNAL state : STATE_TYPE;
    SIGNAL IR, AC : STD_LOGIC_VECTOR(15 DOWNTO 0);
    SIGNAL PC : STD_LOGIC_VECTOR(7 DOWNTO 0);

BEGIN
    -- Asignaciones a puertos de salida
    --	
    AC_out <= AC;
    IR_out <= IR;
    PC_out <= PC;
    FSMD : PROCESS (CLOCK, RESET, state, PC, AC, IR) -- Finite State Machine with Data (¿something?)

    BEGIN

        -- Asignaciones a REGISTROS en datapath y MAQUINA DE ESTADOS de la unidad de control
        IF reset = '1' THEN
            state <= reset_pc;
        ELSIF clock'EVENT AND clock = '1' THEN
            CASE state IS
                WHEN reset_pc => -- Ordenamos a resettear cuando aparezca el siguiente flanco
                    PC <= "00000000";
                    AC <= "0000000000000000";
                    state <= fetch0;
                WHEN fetch0 =>
                    -- Antes de poder usar MEMq en fetch1, necesitamos avisar antes en fetch0
                    state <= fetch1;
                WHEN fetch1 =>
                    IR <= MEMq;
                    PC <= PC + 1;
                    state <= decode;
                WHEN decode =>
                    CASE IR(15 DOWNTO 8) IS
                        WHEN "00000000" =>
                            state <= add0;
                        WHEN "00000001" =>
                            state <= store0;
                        WHEN "00000010" =>
                            state <= load0;
                        WHEN "00000011" =>
                            state <= jump;
                        WHEN OTHERS =>
                            state <= fetch0;
                    END CASE;
                WHEN add0 =>
                    state <= add1;
                WHEN add1 =>
                    AC <= AC + MEMq;
                    state <= fetch0;
                WHEN store0 =>
                    state <= store1;
                WHEN store1 =>
                    state <= fetch0;
                WHEN load0 =>
                    state <= load1;
                WHEN load1 =>
                    AC <= MEMq;
                    state <= fetch0;
                WHEN jump =>
                    PC <= IR(7 DOWNTO 0);
                    state <= fetch0;
                WHEN OTHERS =>
                    state <= fetch0;
            END CASE;
        END IF;

        -- Asignaciones a BUSES de entrada a MEMORIA (Direcciones, Datos y control de escritura)

        CASE state IS
            WHEN fetch0 =>
                MEMadr <= PC;
                MEMwe <= '0';
                MEMdata <= (OTHERS => '-');
            WHEN add0 | load0 =>
                MEMadr <= IR(7 DOWNTO 0);
                MEMwe <= '0';
                MEMdata <= (OTHERS => '-');
            WHEN store0 =>
                MEMadr <= IR(7 DOWNTO 0);
                MEMwe <= '1';
                MEMdata <= AC;
            WHEN OTHERS =>
                MEMadr <= IR(7 DOWNTO 0);
                MEMwe <= '0';
                MEMdata <= (OTHERS => '-');
        END CASE;

    END PROCESS;
END rtl;