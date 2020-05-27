//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i

//static tmpA = ~PINA & 0xFF;

/*complete the state machine*/

void Detect_EQ()
{
    switch(detect_eq_state)
    {
        case DEQInit:
            //init variable(s) here.
		detect_eq_state = DEDetect;
            break;
	case DEDetect:	if(tmpA & 0xF8 == 0){
				detect_eq_state = DENot;
			}
			else{
				detect_eq_state = DEDetect;
			}
			break;
	case DENot:	if(tmpA & 0xF8 == 0){
				detect_eq_state = DENot;
			}
			else{
				detect_eq_state = DEDetect;
			}
        default:
            detect_eq_state = DEQInit;
            break;
    }
    switch(detect_eq_state)
    {
        case DEQInit:
            break;
	case DEDetect:	detect = 1;
			direction = (tmpA & 0x07);
			break;
	case DENot:	detect = 0;
			break;
        default:
            break;
    }
}
