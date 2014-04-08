/* ======This program deals with the manupulation of users, groups and friends of the users. 
         As of now it is working with  users,groups and friends with  scope  
         as same friend with multiple users or same user with multiple groups. 
		 Dletion process of a user includes deletions of that user from all groups and before deletion of
		 a user all the friends of that user should be deleted properly. There should be no any 
		 Duplication of a group or users in a group or friends of a user in a particular group.
		 The program gives following functionality  
		    1.Add a  group
            2.Delete a group        
            3.Add user to a group
            4.Remove a user from a group
            5.Delete a user
            6.Add a Friend
            7.Delete a Friend
            8.List a User Info
            9.List Groups
            10.List friends of a user
            11.List Users of a group
            12.Delete All the friends of a User */

/* ======Platform  Linux 2.6.18-1.2798.fc6xen
   ======Compiler  gcc version 4.1.1 20061011 (Red Hat 4.1.1-30)*/

/* ======Testing Machine  ps4488  
         user name :: root
         Password  :: root123
         path      :: /home/ravi/GroupUser.cpp */


#include<iostream>
#include<string.h>
using namespace std;


/*STRUCTURE FOR FRIEND */
typedef struct Friend
{
   char FriendName[15];
   char UserName[15];
   char GroupName[15];
   struct Friend *next;
}Friend;

/*STRUCTURE FOR USER*/
typedef struct User
{
   char UserName[15];
   char GroupName[15];
   Friend *frd;
   struct User *next;
}User;

/*STRUCTRUE FOR GROUP*/
typedef struct Group
{
    char GroupName[15];
    User *usr;
    struct Group *next;
}Group;


Group *grp=NULL;


/*FUCTION TO CHECK THE DUPLICATE GROUP*/
bool DetectDuplicateGroup(Group *grp,char *name)
{
    Group *gptr = grp;
    while(gptr !=NULL)
    {
       if(!strcmp(gptr->GroupName,name))
         return true;
       gptr = gptr->next;
      
    }
   return false;
}

/*FUNCTION TO SEARCH A GROUP*/
Group *SearchGroup(Group *grp,char *name)
{
   while(grp!=NULL && strcmp(grp->GroupName,name))
      grp = grp->next;

   return grp;

}

/*FUNCTION TO CHECK THE DUPLICATE USER IN A GROUP*/
bool DetectDuplicateUserInGroup(Group *grp, char *uname)
{
    User *uptr;
    Group *gptr;
    gptr = grp;
    uptr = gptr->usr;
    while(uptr!=NULL && strcmp(uptr->UserName,uname))
      uptr = uptr->next;
    if(uptr)
         return true;
       
    return false;
}


/*FUNCTION TO CREATE A GROUP*/
Group *CreateGroup(Group *grp)
{
    Group *ptr,*trace;
    char name[15];
    bool flag;
    trace = grp;
    ptr  = (Group*)malloc(sizeof(Group));
    cout << "Enter the name of Group::" ;
    cin  >> name;
    flag = DetectDuplicateGroup(grp,name);
    if(flag)
    {
      cout <<"Group Allready Exists::" << endl << endl;
      
    }
    else
    {
    	strcpy(ptr->GroupName, name);
    	ptr->next =  NULL;
    	if (grp == NULL)
      	  grp = ptr;
    	else
    	{
       	while(trace->next!= NULL)
          trace = trace->next;  
       	trace->next = ptr;
    	}
    }
    return grp;
      
}


/*FUNCTION TO DELETE A GROUP*/
Group *DeleteGroup(Group *grp)
{
    Group *ptr,*trace,*save;
    char name[15];
    trace = grp;
    save = trace;
    cout << "Enter the name of Group to be Deleted::" ;
    cin  >> name;
    while(strcmp(trace->GroupName,name))
    {     
          save = trace;
          trace = trace->next;
          
    }
    if(trace == NULL)
    {
       cout << "The Entered group does not exits::";
       exit(0);
    }
    else
    {
      save ->next = trace->next;
      free(trace);
    }
    return grp;
}


/*FUNCTION TO DISPLAY A GROUP*/
void DisplayGroup(Group *grp)
{
   Group *ptr;
   ptr = grp;
   if (ptr == NULL)
   {
    cout << "There is no group
    exit(0);
   }
    
   cout << "The groups are::
   while(ptr!=NULL)
    {
     cout <<"     "<< ptr->GroupName << endl;
     ptr = ptr->next;
    }
   
}


/*FUNCTION TO ADD USER TO A GROUP*/
Group *AddUserToGroup(Group *grp)
{
   char gname[15],uname[15];
   Group *ptr;
   User  *tptr,*temp;
   bool flag;
   cout << "These are the existing group::
   DisplayGroup(grp);
   cout <<  "Enter the group of your choice::";
   cin >> gname;
   ptr = SearchGroup(grp,gname);
   if (ptr == NULL)
   {
     cout << "Entered group is not in the list";
     exit(0);
   }
   cout << "Enter the name of user::" ;
   cin >> uname;
   flag = DetectDuplicateUserInGroup(ptr,uname);
   if(flag)
   {
      cout << "The user " << uname << " Already in Group " << gname << endl << endl;
   }      
   else
   {
   	tptr = (User*)malloc(sizeof(User));
   	strcpy(tptr->UserName,uname);
   	strcpy(tptr->GroupName,gname);
   	tptr->next = NULL;
   
   	temp = ptr->usr;
   	if (ptr->usr == NULL)
     	  ptr->usr = tptr;


   	else
     	{
        while(temp->next !=NULL)
           temp = temp->next;

        temp->next = tptr;
          
     	}
   }
    return grp;

}

/*FUNCTION TO DISPLAY USER FOR A PARTICULAR GROUP*/
void DisplayGroupUser(Group *grp)
{

   Group *ptr;
   User  *tptr,*temp;
   char gname[15];
   cout << "These are the existing group::
   DisplayGroup(grp);
   cout <<  "Enter the group of the user::";
   cin >> gname;
   ptr = SearchGroup(grp,gname);
   if (ptr == NULL)
   {
     cout << "Entered group is not in the list";
     exit(0);
   }

   temp = ptr->usr;
   if (ptr->usr == NULL)
    cout << "There is no user in this group" << endl << endl; 

   else
     {
        cout << "The users of the group::" << gname << endl;
        while(temp !=NULL)
         {
           cout <<"    "  << temp->UserName << endl;
           temp = temp->next;
         }

     }

}


/*FUNCTION TO SEARCH A USER*/
User *SearchUser(Group *grp,char *uname)
{
    User *uptr;
    while(grp !=NULL)
    {   
        uptr = grp->usr;
        while(uptr!=NULL && strcmp(uptr->UserName,uname))
          uptr = uptr->next;
        if(uptr)
         return uptr;
       grp = grp->next;
    }
}


/*FUNCTION TO DELETE USER FORM A GROUP*/
Group *DeleteUserFromGroup(Group *grp)
{
   char gname[15],uname[15];
   Group *ptr;
   User  *save,*temp;

   cout << "These are the existing group::
   DisplayGroup(grp);
   cout <<  "Enter the group of the user::";
   cin >> gname;
   ptr = SearchGroup(grp,gname);
   if (ptr == NULL)
   {
     cout << "Entered group is not in the list";
     exit(0);
   }
   cout << "Enter the name of user::" ;
   cin >> uname;
   temp = ptr->usr;
   save = temp;
   while(strcmp(temp->UserName,uname))
   {
        save = temp;
        temp = temp->next;
        
   }
   if (temp == NULL)
   {
        cout << "The User is not in this group::
        exit(0);
   }
   
   else
   {
        save->next = temp->next;
        free (temp);
        cout << "User    " << uname << "     Successfully Deleted
   }
    return grp;
    
}

/*FUNCTON TO FREE FRIEND NODES*/
Friend *DeleteFriends(Friend *fptr)
{
   Friend *temp = fptr;
   while(fptr !=NULL)
   {
      temp = fptr;
      fptr = fptr->next;
      free(temp);
   }
   
  return fptr;
}

/*FUNCTION TO FREE ALL FRIENDS OF A USER*/
Group *DeletingFriends(Group *grp,char *uname)
{
    Group *gptr=grp;
    User  *uptr;
    while(gptr !=NULL)
    {
    	uptr = SearchUser(gptr,uname);
    	if(uptr)
        {
           if(uptr->frd)
             uptr->frd = DeleteFriends(uptr->frd);
        }
    gptr = gptr->next;
   }
   return grp;
}

Group *DeleteAllFriends(Group *grp)
{
    Group *gptr=grp;
    char uname[15];
    cout << "Enter the user name::";
    cin >> uname;
    grp=DeletingFriends(gptr,uname);
    return grp;
}

/*THIS FUNCTION WILL  DELETE A USER FROM ALL GROUPS IF A USER IS IN MULTIPLE GROUPS */
Group *DeleteUser(Group *grp)
{
   char gname[15],uname[15];
   Group *ptr,*gptr=grp;
   User  *uptr,*save,*temp;

   cout << "Enter the name of user::" ;
   cin >> uname;
   while(gptr != NULL)
   {
   	uptr = SearchUser(gptr,uname);
        if(uptr)
        {
                if(uptr->frd)
                   uptr->frd = DeleteFriends(uptr->frd);                
   		strcpy(gname, uptr->GroupName);
   		ptr = SearchGroup(gptr,gname);
   		temp = ptr->usr;
   		save = temp;
   		while(strcmp(temp->UserName,uname))
   		{
        	save = temp;
        	temp = temp->next;
   		}

  	 	save->next = temp->next;
   	 	free (temp);
   	 	cout << "User " << uname << " Successfully Deleted" << " From Group " << gname << endl;
        }
    gptr = gptr->next;
   }
   return grp;

}


/*FUNCTION TO ADD FRIENDS TO A USER OF A GROUP*/
Group *AddFriendUser(Group *grp)
{
  char uname[15], fname[15];
  Group *gptr=grp;
  User *uptr;
  Friend *fptr,*temp;
  cout << "Enter the User name for with Friend is to be Added::" ;
  cin >> uname;
  cout << "Enter the friend name::";
  cin >> fname;
  while(gptr!=NULL)
  {
  	uptr = SearchUser(gptr,uname);
  	if(uptr)
  	{
  		cout << endl;
  		fptr = uptr->frd;

  		temp = (Friend*)malloc(sizeof(Friend));

  		strcpy(temp->FriendName,fname);
  		strcpy(temp->UserName,uname);
  		temp->next = NULL;

  		if(fptr == NULL)
    	  	 uptr->frd = temp;
  
  		else
  		{
     	   	   while(fptr->next !=NULL)
       	     		fptr = fptr->next;
     
     	   	   fptr->next = temp;
  		}
                cout << "Friend " << fname << " Added to User " << uname << "of Group " << gptr->GroupName << " Successfully
        }
        gptr = gptr->next;
  }
  if(uptr == NULL)
  {
     cout << "Entered User not in any Group::
  }
  
  return grp;
}


/*FUNCTION TO DELETE A FRIEND FORM A USER*/
Group *DeleteUserFriend(Group *grp)
{
  char uname[15], fname[15];
  User *uptr;
  Friend *save,*temp;
  cout << "Enter the User name form with Friend is to be Deleted::" ;
  cin >> uname;
  uptr = SearchUser(grp,uname);
  if(uptr == NULL)
  {
    cout << "Entered User not in any Group::
    exit (0);
  }
  cout << endl << endl;
  cout << "Enter the friend name::";
  cin >> fname;
   temp = uptr->frd;
   save = temp;
   while(strcmp(temp->FriendName,fname))
   {
        save = temp;
        temp = temp->next;

   }
   if (temp == NULL)
   {
        cout << "Friend Name not Exits::
        exit(0);
   }

   else
   {
        save->next = temp->next;
        free (temp);
        cout << "Friend    " << fname << "     Successfully Deleted
   }


  return grp;

}

/*FUNCTION TO DISPLAY THE FRIENDS OF A USER*/
void DisplayFriend(Group *grp)
{
  char uname[15];
  User *uptr;
  Friend *fptr;
  cout << "Enter the User name for with Friend is to be Display::" ;
  cin >> uname;
  uptr = SearchUser(grp,uname);
  if(uptr == NULL)
  {
    cout << "Entered User not in any Group::
  }
  cout << endl << endl;

  fptr = uptr->frd;

  if (fptr ==NULL)
  {
     cout << "There is no Friend of user " << uname << endl;
  }
  else
  {
  	cout << "The Friends of the User " << uname << " are::
  	while(fptr !=NULL)
  	{
          cout <<"       "<< fptr->FriendName << endl;
          fptr = fptr->next;
  	}
  }
 
    
}

/*FUNCTION FOR THE INFORMATION OF A USER*/
void DisplayUserInformation(Group *grp)
{
    User *uptr;
    char uname[15];
    Group *gptr = grp;
    Friend *fptr;
    cout << "Enter User Name::";
    cin >> uname;
    if(uptr == NULL)
        cout << "Entered User not in any Group::
    
    cout << "       User Name::" << uname << endl;
    while(gptr != NULL)
    {
        uptr = SearchUser(gptr,uname);
    	cout << "       Group Name::" << uptr->GroupName << endl;
    	fptr = uptr->frd;

    	cout << "The Friends of the User " << uname << "in Group " << gptr->GroupName << " are::
    	while(fptr !=NULL)
    	{
       		cout <<"       "<< fptr->FriendName << endl;
       		fptr = fptr->next;
    	}
     gptr = gptr->next;
    }
    
}
/*MAIN PROGRAM*/
int main()
{
 
    int choice,flag = 1;
    
    do
    {
            cout << "1.Add a  group
            cout << "2.Delete a group        
            cout << "3.Add user to a group
            cout << "4.Remove a user from a group
            cout << "5.Delete a user
            cout << "6.Add a Friend
            cout << "7.Delete a Friend
            cout << "8.List a User Info
            cout << "9.List Groups
            cout << "10.List friends of a user
            cout << "11.List Users of a group
            cout << "12.Delete All the friends of a User
            cout << "13.EXIT" << endl << endl;
            cout << "Enter your choice::";
       cin  >> choice;
       switch(choice)
       {
           case 1: /*Add a  group*/
                   grp = CreateGroup(grp);
                   DisplayGroup(grp);
                   break;

           case 2: /*Delete a groupi*/       
                   grp = DeleteGroup(grp);
                   DisplayGroup(grp); 
                   break;


           case 3: /*Add user to a group*/
                   grp=AddUserToGroup(grp);
                   break;

           case 4:/*Remove a user from a group*/
                   grp = DeleteUserFromGroup(grp);
                   break;

           case 5:/*Delete  a user from a group*/
                   grp = DeleteUser(grp);
                   break;

           case 6: /*Add a Friend*/
                   grp =AddFriendUser(grp);
                   break;

           case 7: /*Delete a Friend*/
                   grp = DeleteUserFriend(grp);
                   break;

           case 8: /*List a User Info*/
                   DisplayUserInformation(grp);
                   break;

           case 9: /*List Groups*/
                    DisplayGroup(grp);
                   break;

           case 10: /*List friends of a user*/
                   DisplayFriend(grp);
                   break;

           case 11: /*List Users of a group*/
                    DisplayGroupUser(grp);
                   break;
                   
           case 12:/*Delete All the friends of a User*/
                     grp = DeleteAllFriends(grp);
                     break;

           case 13: /*Exit*/
                    flag = 0;
                    break;

          default:  cout <<endl << endl << "You have Entered a Invald Choice
                    

       }
    
    }while(flag);
}
