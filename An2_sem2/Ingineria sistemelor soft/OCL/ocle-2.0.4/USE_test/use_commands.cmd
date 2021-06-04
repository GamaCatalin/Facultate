-- Sample USE command file submitted by Vladimir Mencl and Jiri Samek from Distributed Systems Research Group, Charles University, Prague

!create a : A
!create b : B
!create sb : specB

-- This association is loaded without problems.
!insert (a, b) into A_A_B

-- In previous versions, this one isn't loaded and the message "Object type does not conform to classifier type" is printed in the command window.
-- In ocle 2.0.4 this bug is resolved.

!insert (a, sb) into A_A_B

