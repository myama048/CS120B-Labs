
//define local variable(s) here.  Use static keyword to keep local, e.g:
//   static int i;  // defines a local int named i
static int i = 0;
static int H = 1;
static int L = 9;


/*complete the state machine*/

void Ping()
{
    switch(ping_state)
    {
        case PInit:	ping_state = PHigh;
			ping = 0;
			i = 0;
            		break;
	case PHigh:	if(i > H){
				ping_state = PLow;
				i = 0;
			}
			else{
				ping_state = PHigh;
			}
			break;
	case PLow:	if(i > L){
				ping_state = PHigh;
				i = 0;
			}
			else{
				ping_state = PLow;
			}
			break;
        default:
            ping_state = PInit;
            break;
    }
    switch(ping_state)
    {
        case PInit:
            break;
	case PHigh:	ping = 1;
			i++;
			break;
	case PLow:	ping = 0;
			i++;
			break;
        default:
            break;
    }
}
