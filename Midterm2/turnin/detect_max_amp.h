
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static unsigned char tmp = 0;
//static unsigned char tmpA = ~PINA & 0xFF;
/* complete the state machine. */

void Detect_Max_Amp()
{
    switch(detect_max_amp_state)
    {
        case DMAInit:	detect_max_amp_state = Max;
			max = 0;
           		break;
        case Max:	detect_max_amp_state = Max;
			break;
        default:
            break;
    }
    switch(detect_max_amp_state)
    {
        case DMAInit:
            break;
	case Max:	tmp = (tmpA & 0xF8) >> 3;
			if(tmp > max){
				max = tmp;
			}
			break;
        default:
            break;
    }
}
