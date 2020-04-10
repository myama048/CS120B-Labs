# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n


test "PINA: 0x01, PINB: 0x02, PINC: 0x01 => PORTD: 0x04"
setPINA 0x01
setPINB 0x02
setPINC 0x01
continue 2
expectPORTD 0x04
checkResult
#Add tests below

test "PINA: 0x02, PINB: 0x00, PINC => PORTD: 0x40"
setPINA 64
setPINB 0
setPINC 0
continue 2
expectPORTD 0x40
checkResult

test "PINA 3, PINB 0, PINC 0 => PORTD: 0xA3"
setPINA 100
setPINB 50
setPINC 10
continue 2
expectPORTD 0xA3
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo passed %d%d tests.\n",$passed,$tests
echo =====================================================\n
