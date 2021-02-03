-- Q -------- PROGRAM ----------------- NODE ------------

-- 1 ----- Car_Headlight ------------ Headlight ---------
-- 2 -- Traffic_Light_Controller ----- Decoder ----------
-- 3 -------- Counter -------------- Mod12Counter -------


--Q-----DESCRIPTION--------------------------------------

  1	The output is working correctly

  2	The output is working as expected by the designer.
	The main road is always open unless interrupted by a vehicle from the side road. In that case, the main road closes and the side road traffic light is GREEN for a sequence of 10 seconds (GREEN-RED-GREEN-RED- ...). This is specialized for each side road entrance.
	The exits from the junction are not considered in the given problem statement since any vehicle may choose to go to any exit.

  3	The counter is not exact and has an issue:
	The RESET button is not working properly. Whenever the issue is tried to be solved using an internal RESET for the JK FlipFlop, the output come out as NIL.	Because the RESET is not working properly, the sequence of numbers after 12 which need to be reset to 0 still show up in the second half of the clock cycle.
