LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

-- Conversor de hexadecimal a codigo de 7 segmentos
-- Los LEDs se iluminan en baja

ENTITY dec_7seg IS
	
	PORT(hex_digit		: IN	STD_LOGIC_VECTOR(3 DOWNTO 0);
		 seg_digit		: OUT STD_LOGIC_VECTOR(0 TO 13));

END dec_7seg;

ARCHITECTURE a OF dec_7seg IS
	
BEGIN
	PROCESS  (Hex_digit)
		
	BEGIN
		
	  CASE Hex_digit IS
         WHEN "0000" =>
             seg_digit <= "00000000000001";
         WHEN "0001" =>
             seg_digit <= "00000001001111";
         WHEN "0010" =>
             seg_digit <= "00000000010010";
         WHEN "0011" =>
             seg_digit <= "00000000000110";
         WHEN "0100" =>
             seg_digit <= "00000001001100";
       	 WHEN "0101" =>
             seg_digit <= "00000000100100";
       	 WHEN "0110" =>
             seg_digit <= "00000000100000";
    	 WHEN "0111" =>
             seg_digit <= "00000000001111";
 	     WHEN "1000" =>
             seg_digit <= "00000000000000";
     	 WHEN "1001" =>
             seg_digit <= "00000000000100"; 
			WHEN "1010" =>
				seg_digit <=  "10011110000001";
			WHEN "1011" =>
				seg_digit <=  "10011111001111";
	   	 WHEN OTHERS =>
        	 seg_digit <= "00000001000001";
	  END CASE;
	END PROCESS;
	
	

END a;

