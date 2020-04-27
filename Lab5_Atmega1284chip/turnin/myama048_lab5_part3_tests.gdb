# Test file for "Lab5_Atmega1284chip"


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
test "PINA: 0x00 => PORTC: 04"
# Set inputs
setPINA 0
# Continue for several ticks
continue 2
# Set expect values
expectPORTC 0x00
# Check pass/fail
checkResult

# Add tests below
test "1"
setPINA 1
continue 2
expectPORTC 1
checkResult

test "1-"
setPINA 0
continue 2
expectPORTC 1
checkResult

test "2"
setPINA 3
continue 2
expectPORTC 1
checkResult

test "2-"
setPINA 0
continue 2
expectPORTC 1
checkResult

test "3"
setPINA 1
continue 2
expectPORTC 2
checkResult

test "3-"
setPINA 0
continue 2
expectPORTC 2
checkResult

test "4"
setPINA 1
continue 2
expectPORTC 4
checkResult

test "4-"
setPINA 0
continue 2
expectPORTC 4
checkResult

test "5"
setPINA 1
continue 2
expectPORTC 8
checkResult

test "5-"
setPINA 0
continue 2
expectPORTC 8
checkResult

test "5.2"
setPINA 1
continue 2
expectPORTC 0x10
checkResult

test "5.2-"
setPINA 0
continue 2
expectPORTC 0x10
checkResult

test "6"
setPINA 1
continue 2
expectPORTC 0x20
checkResult

test "7"
setPINA 1
continue 2
expectPORTC 0x20
checkResult

test "7-"
setPINA 0
continue 2
expectPORTC 0x20
checkResult

test "7.1"
setPINA 1
continue 2
expectPORTC 0x40
checkResult

test "7.1-"
setPINA 0
continue 2
expectPORTC 0x40
checkResult

test "8"
setPINA 1
continue 2
expectPORTC 0x80 #change
checkResult

test "8.8"
setPINA 0
continue 2
expectPORTC 0x80
checkResult

test "9"
setPINA 1
continue 2
expectPORTC 0x40
checkResult

test "9-"
setPINA 0
continue 2
expectPORTC 0x40
checkResult

test "10"
setPINA 1
continue 2
expectPORTC 0x20
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n