	       /**CALANDER PROGRAMME**/

/* FUNCTION FOR FINDING THE DAY */
 dayfound(int dd,int yyyy)
  {
   int y=0,k=0,oryr=0,odd=0,lpyr=0,oddm=0,nmon=0,febd=0,ndays=0,oddy=0,yyy=0,l=0,k1;
   int count=0;
   yyy=yyyy-1;
    k=yyy/400;
    y=yyy-k*400;

       if(y%400==0)
	   odd=0;
	   else if((y>=100)&&(y%400!=0))
	     {
	       k1=y/100;
	       l=k1*5;
	       odd=odd+l%7;
	       y=y-k1*100;
	       }
	      if(y<100)
		{
	      lpyr=y/4;
	      oryr=y-lpyr;
	      oddy=(lpyr*2+oryr*1)%7;
	      odd=odd+oddy;
	      }

	if(yyyy%4==0)
	  febd=29;
	  count=0;
	 else
	  febd=28;

/* find the month of the given day*/
	  if(dd>31)
	   {
	    dd=dd-31
	     count++;
	    if(dd>28)
	     {
	      dd=dd-febd;
	       count++;
	       if(dd>31)
		{
		dd=dd-31
		 count++;
		 if(dd>30)
		 {
		  dd=dd-30;
		  count++;
		  if(dd>31)
		  {
		   dd=dd-31;
		   count++;
		    if(dd>30)
		    {
		     dd=dd-30;
		     count++;
		      if(dd>31)
		       {
		       dd=dd-31;
		       count++;
			if(dd>31)
			{
			 dd=dd-31;
			  count++;
			  if(dd>30)
			  {
			   dd=dd-30;
			   count++;
			   if(dd>31)
			   {
			    dd=dd-31;
			    count++;
			    if(dd>30)
			    {
			    dd=dd-30;
			    count++;
			     if(dd>31)
			     {
			     dd=dd-31;
			     count++;
			     }
			   }
			  }
			}
		      }
		     }
		   }
		 }
		}
	       }
	      }
	    }
	switch(nmon)
	  {
	    case 0:
		   ndays=dd;
		   oddm=ndays%7;
		   break;
	    case 1:
		   ndays=31+dd;
		   oddm=ndays%7;
		   break;
	     case 2:
		     ndays=31+febd+dd;
		     oddm=ndays%7;
		     break;
	       case 3:
		     ndays=31+febd+31+dd;
		     oddm=ndays%7;
		     break;
		case 4:
		     ndays=31+febd+31+30+dd;
		     oddm=ndays%7;
		     break;
		case 5:
		      ndays=31+febd+31+30+31+dd;
		      oddm=ndays%7;
		      break;
		case 6:
		      ndays=31+febd+31+30+31+30+dd;
		      oddm=ndays%7;
		      break;
		 case 7:
		      ndays=31+febd+31+30+31+30+31+dd;
		      oddm=ndays%7;
		      break;
		 case 8:
		      ndays=31+febd+31+30+31+30+31+31+dd;
		      oddm=ndays%7;
		      break;
		 case 9:
		      ndays=31+febd+31+30+31+30+31+31+30+dd;
		      oddm=ndays%7;
		      break;
		 case 10:
		       ndays=31+febd+31+30+31+30+31+31+30+31+dd;
		       oddm=ndays%7;
		       break;
		  case 11:
		       ndays=31+febd+31+30+31+30+31+31+30+31+30+dd;
		       oddm=ndays%7;
		       break;
		}

	odd=odd+oddm;
	odd=odd%7;
	switch(odd)
	 {
	  case 0:
		printf("\n The day of the entered date is:: Sun");
		break;
	  case 1:
		printf("\n The day of the entered date is:: Mon");
		break;
	  case 2:
		printf("\n The day of the entered date is:: Tue");
		break;
	  case 3:
		printf("\n The day of the entered date is:: Wed");
		break;
	  case 4:
		printf("\n The day of the entered date is:: Thrusday");
		break;
	  case 5:
		printf("\n The day of the entered date is:: Friday");
		break;
	  case 6:
		printf("\n The day of the entered date is:: Saturday");
		break;
	   default:
		printf("\n wrong format of date is entered try again");
	     }
	}


   /* MAIN FUNCTION*/
void main()
{
 int dd,mm,yyyy=0;
 clrscr();
 printf("\n enter the date in the format of dd/mm/yyyy::");
 scanf("%d%*c%d%*c%d",&dd,&mm,&yyyy);
 dayfound(dd,mm,yyyy);
 getch();
 }