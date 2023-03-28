LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY my_scomp_v0_0 IS
    PORT (
        reloj : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        SW : IN STD_LOGIC_VECTOR(7 DOWNTO 0); -- IO IN (6.4)
        CONT : IN STD_LOGIC; -- CONT (6.5)
        IR_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
        AC_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
        PC_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
        LEDG_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); -- IO OUT (6.4)
        SP_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0) -- Stack Pointer (6.5)
    );
END my_scomp_v0_0;

ARCHITECTURE rtl OF my_scomp_v0_0 IS

    SIGNAL MEMq, MEMdata : STD_LOGIC_VECTOR(15 DOWNTO 0);
    SIGNAL MEMadr : STD_LOGIC_VECTOR(7 DOWNTO 0);
    SIGNAL MEMwe : STD_LOGIC;

    -- Declaracion del IP core ram_256_x_16
    --
    -- 	Memoria RAM de un puerto, 256 palabras, 16 bits por palabra,
    -- 	Entradas de datos, direcciones y control de memoria REGISTRADAS,
    -- 	Salida NO REGISTRADA
    -- 	Fichero de inicializacion: programa.mif
    COMPONENT IP_ram_256_x_16
        PORT (
            address : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
            clock : IN STD_LOGIC := '1';
            data : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
            wren : IN STD_LOGIC;
            q : OUT STD_LOGIC_VECTOR (15 DOWNTO 0)
        );
    END COMPONENT;

    -- Declaracion del componente con versión inicial del procesador 
    --

    COMPONENT procesador_v2_5 IS
        PORT (
            clock : IN STD_LOGIC;
            reset : IN STD_LOGIC;
            SW : IN STD_LOGIC_VECTOR(7 DOWNTO 0); -- IN (6.4)
            CONT : IN STD_LOGIC; -- CONT (6.5)
            AC_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
            IR_out : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
            PC_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
            LEDG_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); -- OUT (6.4)
            SP_out : OUT STD_LOGIC_VECTOR(7 DOWNTO 0); -- Stack Pointer (6.5)
            MEMq : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
            MEMdata : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
            MEMwe : OUT STD_LOGIC;
            MEMadr : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)
        );
    END COMPONENT;
BEGIN

    -- Instancia denominada MEM del IP core ram_256_x_16
    --
    MEM : IP_RAM_256_x_16 PORT MAP(-- Los puertos son señales
        address => MEMadr,
        clock => reloj,
        data => MEMdata,
        wren => MEMwe,
        q => MEMq
    );

    -- Instancia denominada PROC de la version inicial del procesador
    --

    PROC : procesador_v2_5 PORT MAP(
        clock => reloj,
        reset => reset,
        SW => SW,
        CONT => CONT,
        AC_out => AC_out,
        IR_out => IR_out,
        PC_out => PC_out,
        LEDG_out => LEDG_out,
        SP_out => SP_out,
        MEMq => MEMq,
        MEMdata => MEMdata,
        MEMwe => MEMwe,
        MEMadr => MEMadr
    );
END rtl;