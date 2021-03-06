# Test file for "Lab4_SMs"


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

# Example test:
test "1"
# Set inputs
setPINA 0x00
# Continue for several ticks
continue 2
# Set expect values
expectPORTB 0
# Check pass/fail
checkResult

# Add tests below
test "2"
setPINA 0x03
continue 2
expectPORTB 0
checkResult

test "3"
setPINA 0x04
continue 2
expectPORTB 0
checkResult

test "3-2"
setPINA 0
continue 2
expectPORTB 0
checkResult

test "3-3"
setPINA 0x02
continue 2
expectPORTB 0x01
checkResult


test "4"
setPINA 0x04
continue 2

test "4.1"
setPINA 0x00
continue 2

test "4.2"
setPINA 0x02
continue 2
expectPORTB 0x00
checkResult

test "5"
setPINA 0x04
continue 2

test "5.1"
setPINA 0x00
continue 2

teset "5.2"
setPINA 0x02
continue 2
expectPORTB 0x00
checkResult

test "6"
setPINA 0x80
continue 2
expectPORTB 0x00
checkResult



test "5"
setPINA 0x04
continue 1
expectPORTB 0
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
