#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef char vfi_char_t;

struct vxfi_objid {
        vfi_char_t      *vid_name;
        int             vid_len; /* in bytes */
        int             vid_type;
};
typedef struct vxfi_objid vxfi_objid_t;

typedef vxfi_objid_t    vfi_objid_t;

void fi_find_claimant_With_Pointer_address( vfi_objid_t **priobjid)
{
	printf("The fi_find_claimant_With_Pointer_address value With -> is [%s]\n",(*priobjid)->vid_name);
	printf("The fi_find_claimant_With_Pointer_address value With . is [%s]\n",(**priobjid).vid_name);
}

void fi_find_claimant_With_Pointer_Value( vfi_objid_t *priobjid)
{
	printf("The priobjid fi_find_claimant_With_Pointer_Value value With -> is [%s]\n",priobjid->vid_name);
	printf("The priobjid fi_find_claimant_With_Pointer_Value value With . is [%s]\n",(*priobjid).vid_name);
}

void fi_find_claimant_With_Structure_address( vfi_objid_t *priobjid)
{
	printf("The fi_find_claimant_With_Structure_address value  With -> is [%s]\n",priobjid->vid_name);
	printf("The priobjid fi_find_claimant_With_Pointer_Value With . value is [%s]\n",(*priobjid).vid_name);
}

void fi_find_claimant_With_Structure_value( vfi_objid_t priobjid)
{
	printf("The fi_find_claimant_With_Structure_value value  With . is [%s]\n",priobjid.vid_name);
	//printf("The priobjid fi_find_claimant_With_Pointer_Value With . value is [%s]\n",(*priobjid).vid_name);
}
int main(){
 
  //Create the Object on Heap and pass by address
  vfi_objid_t *primary;
  primary = (vfi_objid_t*)malloc(sizeof(vfi_objid_t));
  primary->vid_name = (char*)malloc(15*sizeof(char));
  strcpy(primary->vid_name,"Ravi Ranjan");
  primary->vid_len = 10;
  primary->vid_type = 2;
  fi_find_claimant_With_Pointer_address(&primary);

  //Create the object on Heap and pass by value
  fi_find_claimant_With_Pointer_Value(primary);

  //Create the object on Stack and pass by address
  vfi_objid_t primary2;
  primary2.vid_len = 10;
  primary2.vid_type = 2;
  primary2.vid_name = (char*)malloc(15*sizeof(char));
  strcpy(primary2.vid_name,"Neeharika Ranjan");
  fi_find_claimant_With_Structure_address(&primary2);

  //Create the object on Stack and pass by value
  fi_find_claimant_With_Structure_value(primary2);
  return 0;
}

