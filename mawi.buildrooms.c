#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <limits.h>

  // initializes the hard-coded rooms/types/names in an array 
  const char* rooms[] = {"Sun","Moon","Cloud","Wind","Earth","Ground","Air","Heaven","Land","Ocean"};
  const char* room_types[] = {"START_ROOM","MID_ROOM","MID_ROOM","MID_ROOM","MID_ROOM","MID_ROOM","END_ROOM"};
  char room_names[7][8] = {"Room 1","Room 2","Room 3","Room 4","Room 5","Room 6","Room 7",};
  
  // creates room connection structure connections and rooms
  struct Room{
    int  c1;
    int  c2;
    int  c3;
    int  c4;
    int  c5;
    int  c6;
    int count;
  };
  struct Room Room_1;
  struct Room Room_2;
  struct Room Room_3;
  struct Room Room_4;
  struct Room Room_5;
  struct Room Room_6;
  struct Room Room_7;

  /*Adds a room connection to the structure(total of 6 possible connections)
    Uses a counter to check how many connections are already in each room 1-7 and adds the 
    connection based on that count*/
int ConnectRoom(int x,int y){
  if (x == 1){
    if (Room_1.count == 0){
      Room_1.c1 = y;
      Room_1.count = Room_1.count + 1;
    }
    else if (Room_1.count == 1){
      Room_1.c2 = y;
      Room_1.count = Room_1.count + 1;
    }
    else if (Room_1.count == 2){
      Room_1.c3 = y;
      Room_1.count = Room_1.count + 1;
    }
    else if (Room_1.count == 3){
      Room_1.c4 = y;
      Room_1.count = Room_1.count + 1;
    }
    else if (Room_1.count == 4){
      Room_1.c5 = y;
      Room_1.count = Room_1.count + 1;
    }  
    else if (Room_1.count == 5){
      Room_1.c6 = y;
      Room_1.count = Room_1.count + 1;
    }      
}else if (x == 2){
    if (Room_2.count == 0){
      Room_2.c1 = y;
      Room_2.count = Room_2.count + 1;
    }
    else if (Room_2.count == 1){
      Room_2.c2 = y;
      Room_2.count = Room_2.count + 1;
    }
    else if (Room_2.count == 2){
      Room_2.c3 = y;
      Room_2.count = Room_2.count + 1;
    }
    else if (Room_2.count == 3){
      Room_2.c4 = y;
      Room_2.count = Room_2.count + 1;
    } 
    else if (Room_2.count == 4){
      Room_2.c5 = y;
      Room_2.count = Room_2.count + 1;
    } 
    else if (Room_2.count == 5){
      Room_2.c6 = y;
      Room_2.count = Room_2.count + 1;
    }   
}else if (x == 3){
    if (Room_3.count == 0){
      Room_3.c1 = y;
      Room_3.count = Room_3.count + 1;
    }
    else if (Room_3.count == 1){
      Room_3.c2 = y;
      Room_3.count = Room_3.count + 1;
    }
    else if (Room_3.count == 2){
      Room_3.c3 = y;
      Room_3.count = Room_3.count + 1;
    }
    else if (Room_3.count == 3){
      Room_3.c4 = y;
      Room_3.count = Room_3.count + 1;
    } 
    else if (Room_3.count == 4){
      Room_3.c5 = y;
      Room_3.count = Room_3.count + 1;
    } 
    else if (Room_3.count == 5){
      Room_3.c6 = y;
      Room_3.count = Room_3.count + 1;
    }   
}else if (x == 4){
    if (Room_4.count == 0){
      Room_4.c1 = y;
      Room_4.count = Room_4.count + 1;
    }
    else if (Room_4.count == 1){
      Room_4.c2 = y;
      Room_4.count = Room_4.count + 1;
    }
    else if (Room_4.count == 2){
      Room_4.c3 = y;
      Room_4.count = Room_4.count + 1;
    }
    else if (Room_4.count == 3){
      Room_4.c4 = y;
      Room_4.count = Room_4.count + 1;
    }
    else if (Room_4.count == 4){
      Room_4.c5 = y;
      Room_4.count = Room_4.count + 1;
    }
    else if (Room_4.count == 5){
      Room_4.c6 = y;
      Room_4.count = Room_4.count + 1;
    }
}else if (x == 5){
    if (Room_5.count == 0){
      Room_5.c1 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 1){
      Room_5.c2 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 2){
      Room_5.c3 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 3){
      Room_5.c4 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 4){
      Room_5.c5 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 5){
      Room_5.c6 = y;
      Room_5.count = Room_5.count + 1;
    }  
}else if (x == 5){
    if (Room_5.count == 0){
      Room_5.c1 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 1){
      Room_5.c2 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 2){
      Room_5.c3 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 3){
      Room_5.c4 = y;
      Room_5.count = Room_5.count + 1;
    }
    else if (Room_5.count == 4){
      Room_5.c5 = y;
      Room_5.count = Room_5.count + 1;
    } 
    else if (Room_5.count == 5){
      Room_5.c6 = y;
      Room_5.count = Room_5.count + 1;
    } 
}else if (x == 6){
    if (Room_6.count == 0){
      Room_6.c1 = y;
      Room_6.count = Room_6.count + 1;
    }
    else if (Room_6.count == 1){
      Room_6.c2 = y;
      Room_6.count = Room_6.count + 1;
    }
    else if (Room_6.count == 2){
      Room_6.c3 = y;
      Room_6.count = Room_6.count + 1;
    }
    else if (Room_6.count == 3){
      Room_6.c4 = y;
      Room_6.count = Room_6.count + 1;
    }
    else if (Room_6.count == 4){
      Room_6.c5 = y;
      Room_6.count = Room_6.count + 1;
    }  
    else if (Room_6.count == 5){
      Room_6.c6 = y;
      Room_6.count = Room_6.count + 1;
    }  
}else if (x == 7){
    if (Room_7.count == 0){
      Room_7.c1 = y;
      Room_7.count = Room_7.count + 1;
    }
    else if (Room_7.count == 1){
      Room_7.c2 = y;
      Room_7.count = Room_7.count + 1;
    }
    else if (Room_7.count == 2){
      Room_7.c3 = y;
      Room_7.count = Room_7.count + 1;
    }
    else if (Room_7.count == 3){
      Room_7.c4 = y;
      Room_7.count = Room_7.count + 1;
    }
    else if (Room_7.count == 4){
      Room_7.c5 = y;
      Room_7.count = Room_7.count + 1;
    } 
    else if (Room_7.count == 5){
      Room_7.c6 = y;
      Room_7.count = Room_7.count + 1;
    }
}
return 0;
} 
 
 // checks to see if a connection int is already established in the room struct
int ConnectionAlreadyExists(int x, int y){
  if (x == 1){
    if (Room_1.c1 == y || Room_1.c2 == y|| Room_1.c3 == y|| Room_1.c4 == y|| Room_1.c5 == y|| Room_1.c6 == y){
      return 1;
    }
  }if (x == 2){
    if (Room_2.c1 == y || Room_2.c2 == y|| Room_2.c3 == y|| Room_2.c4 == y|| Room_2.c5 == y|| Room_2.c6 == y){
      return 1;
    }
  }if (x == 3){
    if (Room_3.c1 == y || Room_3.c2 == y|| Room_3.c3 == y|| Room_3.c4 == y|| Room_3.c5 == y|| Room_3.c6 == y){
      return 1;
    }
  }if (x == 4){
    if (Room_4.c1 == y || Room_4.c2 == y|| Room_4.c3 == y|| Room_4.c4 == y|| Room_4.c5 == y|| Room_4.c6 == y){
      return 1;
    }
  }if (x == 5){
    if (Room_5.c1 == y || Room_5.c2 == y|| Room_5.c3 == y|| Room_5.c4 == y|| Room_5.c5 == y|| Room_5.c6 == y){
      return 1;
    }
  }if (x == 6){
    if (Room_6.c1 == y || Room_6.c2 == y|| Room_6.c3 == y|| Room_6.c4 == y|| Room_6.c5 == y|| Room_6.c6 == y){
      return 1;
    }
  }if (x == 7){
    if (Room_7.c1 == y || Room_7.c2 == y|| Room_7.c3 == y|| Room_7.c4 == y|| Room_7.c5 == y|| Room_7.c6 == y){
      return 1;
    }
  }
  return 0;
}
    
   // checks to see if room is the same using the array of rooms, returns true if same
int IsSameRoom(int x,int y){
  if (rooms[x] == rooms[y]){
    return 1;
  }
  else{
    return 0;
}
    }

  //returns a random room number from the rooms array using rand() function
int GetRandomRoom(){
  srand(time(NULL)); 
  int r = rand() % 8;
  return r;
}

  //checks whether or not room struct has less than 6 connections using counter
int CanAddConnectionFrom(int x){
  if (x==1){
    if (Room_1.count < 6){
      return 1;
    }
  }
  if (x==2){
    if (Room_2.count < 6){
      return 1;
    }
  }
  if (x==3){
    if (Room_3.count < 6){
      return 1;
    }
  }
  if (x==4){
    if (Room_4.count < 6){
      return 1;
    }
  }if (x==5){
    if (Room_5.count < 6){
      return 1;
    }
  }if (x==6){
    if (Room_6.count < 6){
      return 1;
    }
  }if (x==7){
    if (Room_7.count < 6){
      return 1;
    }
  }
  return 0;
}

 //if connections is greater than 2 for all rooms, returns true,else false 
int IsGraphFull(){
  if (Room_1.count > 2 && Room_2.count > 2 && Room_3.count > 2 && Room_4.count > 2 && Room_5.count > 2 && Room_6.count > 2 &&
  Room_7.count > 2){
    return 1;
  }else{
    return 0;
  }
}

/*  Takes two rooms selected randomly and checks if a connection can be added, connects those 
    two rooms */
int AddRandomConnection(){
  int a;
  int b;

  while(1){
    a = GetRandomRoom();  // gets a random room for a and checks if that room can add 
    if (CanAddConnectionFrom(a) == 1)
      break;
  }
  do{
    b = GetRandomRoom();  // gets a random room for b
  }
  while(CanAddConnectionFrom(b) == 0 || IsSameRoom (a,b) == 1 || ConnectionAlreadyExists(a,b) == 1);
    ConnectRoom(a,b);
    ConnectRoom(b,a);   //connections both rooms back and forth if not same room and can be                           added
  return 0;
}

// shuffles the array of the room types for randomization
void RandomRoomTypes(){
  int size = 7;
  if (size > 1){
    int i;
    for (int i = 0; i <size - 1; i++){
      int j = rand() % size;    // loops through array and gets random index and shuffles
      const char* temp = room_types[j];
      room_types[j] = room_types[i];
      room_types[i] = temp;
    }
  }
}

// shuffles array of the rooms for randomization 
void RandomRooms(){
  int size = 7;
  if (size > 1){
    int i;
    for (int i = 0; i <size - 1; i++){ // loops through array and gets random index and shuffles
      int j = rand() % size;
      const char* temp = rooms[j];
      rooms[j] = rooms[i];
      rooms[i] = temp;
    }
  }
}

int main(void) {

  // randomizes the array order
  srand(time(NULL));
  RandomRooms();
  RandomRoomTypes();
  
  //creates a new rooms directory with a random int 
  int i = rand() % 100001;
  int dir;
  char file[30] = "./mawi.rooms.";
  sprintf(file, "./mawi.rooms.%d/", i);
  dir = mkdir(file, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
 
  // call function to fully build the room connections
while (IsGraphFull() == 0){
   AddRandomConnection();
 }

// creates 7 char that is used to concatenate with the dir name
char A[20];
char B[20];
char C[20];
char D[20];
char E[20];
char F[20];
char G[20];
// strcpy the new directory name into the created char 
strcpy(A,file);
strcpy(B,file);
strcpy(C,file);
strcpy(D,file);
strcpy(E,file);
strcpy(F,file);
strcpy(G,file);
// strcat the file directory name path with the name of rooms 
strcat(A, rooms[1]);
strcat(B, rooms[2]);
strcat(C, rooms[3]);
strcat(D, rooms[4]);
strcat(E, rooms[5]);
strcat(F, rooms[6]);
strcat(G, rooms[7]);

// Following codes opens and creates room files with correct name using the created concatenated chars and connections/room type. Adds all connection room names if available 
  int r1;
  r1 = open(A, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  char name[] = "ROOM NAME: ";
  write(r1, name, strlen(name));
  write(r1,rooms[1],strlen(rooms[1]));
  char message[] = "\nCONNECTION 1: ";
  write(r1, message, strlen(message));
  write(r1, rooms[Room_1.c1], strlen(rooms[Room_1.c1]));
  char message1[] = "\nCONNECTION 2: ";
  write(r1, message1, strlen(message1));
  write(r1, rooms[Room_1.c2], strlen(rooms[Room_1.c2]));
  char message2[] = "\nCONNECTION 3: ";
  write(r1, message2, strlen(message2));
  write(r1, rooms[Room_1.c3], strlen(rooms[Room_1.c3]));
  if (Room_1.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r1, message3, strlen(message3));
  write(r1, rooms[Room_1.c4], strlen(rooms[Room_1.c4]));
  }
  if (Room_1.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r1, message4, strlen(message4));
  write(r1, rooms[Room_1.c5], strlen(rooms[Room_1.c5]));
  }
  if (Room_1.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r1, message5, strlen(message5));
  write(r1, rooms[Room_1.c6], strlen(rooms[Room_1.c6]));
  }
  char type[] = "\nROOM TYPE: ";
  write(r1, type, strlen(type));
  write(r1,room_types[0],strlen(room_types[0]));
  close(r1);

  int r2;
  r2 = open(B, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  write(r2, name, strlen(name));
  write(r2,rooms[2],strlen(rooms[2]));
  write(r2, message, strlen(message));
  write(r2, rooms[Room_2.c1], strlen(rooms[Room_2.c1]));
  write(r2, message1, strlen(message1));
  write(r2, rooms[Room_2.c2], strlen(rooms[Room_2.c2]));
  write(r2, message2, strlen(message2));
  write(r2, rooms[Room_2.c3], strlen(rooms[Room_2.c3]));
  if (Room_2.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r2, message3, strlen(message3));
  write(r2, rooms[Room_2.c4], strlen(rooms[Room_2.c4]));
  }
  if (Room_2.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r2, message4, strlen(message4));
  write(r2, rooms[Room_2.c5], strlen(rooms[Room_2.c5]));
  }
  if (Room_2.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r2, message5, strlen(message5));
  write(r2, rooms[Room_2.c6], strlen(rooms[Room_2.c6]));
  }
  write(r2, type, strlen(type));
  write(r2,room_types[1],strlen(room_types[1]));
  close(r2);

  int r3;
  r3 = open(C, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  write(r3, name, strlen(name));
  write(r3,rooms[3],strlen(rooms[3]));
  write(r3, message, strlen(message));
  write(r3, rooms[Room_3.c1], strlen(rooms[Room_3.c1]));
  write(r3, message1, strlen(message1));
  write(r3, rooms[Room_3.c2], strlen(rooms[Room_3.c2]));
  write(r3, message2, strlen(message2));
  write(r3, rooms[Room_3.c3], strlen(rooms[Room_3.c3]));
  if (Room_3.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r3, message3, strlen(message3));
  write(r3, rooms[Room_3.c4], strlen(rooms[Room_3.c4]));
  }
  if (Room_3.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r3, message4, strlen(message4));
  write(r3, rooms[Room_3.c5], strlen(rooms[Room_3.c5]));
  }
  if (Room_3.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r3, message5, strlen(message5));
  write(r3, rooms[Room_3.c6], strlen(rooms[Room_3.c6]));
  }
  write(r3, type, strlen(type));
  write(r3,room_types[2],strlen(room_types[2]));
  close(r3);

  int r4;
  r4 = open(D, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  write(r4, name, strlen(name));
  write(r4,rooms[4],strlen(rooms[4]));
  write(r4, message, strlen(message));
  write(r4, rooms[Room_4.c1], strlen(rooms[Room_4.c1]));
  write(r4, message1, strlen(message1));
  write(r4, rooms[Room_4.c2], strlen(rooms[Room_4.c2]));
  write(r4, message2, strlen(message2));
  write(r4, rooms[Room_4.c3], strlen(rooms[Room_4.c3]));
  if (Room_4.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r4, message3, strlen(message3));
  write(r4, rooms[Room_4.c4], strlen(rooms[Room_4.c4]));
  }
  if (Room_4.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r4, message4, strlen(message4));
  write(r4, rooms[Room_4.c5], strlen(rooms[Room_4.c5]));
  }
  if (Room_4.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r4, message5, strlen(message5));
  write(r4, rooms[Room_4.c6], strlen(rooms[Room_4.c6]));
  }
  write(r4, type, strlen(type));
  write(r4,room_types[3],strlen(room_types[3]));
  close(r4);

  int r5;
  r5 = open(E, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  write(r5, name, strlen(name));
  write(r5,rooms[5],strlen(rooms[5]));
  write(r5, message, strlen(message));
  write(r5, rooms[Room_5.c1], strlen(rooms[Room_5.c1]));
  write(r5, message1, strlen(message1));
  write(r5, rooms[Room_5.c2], strlen(rooms[Room_5.c2]));
  write(r5, message2, strlen(message2));
  write(r5, rooms[Room_5.c3], strlen(rooms[Room_5.c3]));
  if (Room_5.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r5, message3, strlen(message3));
  write(r5, rooms[Room_5.c4], strlen(rooms[Room_5.c4]));
  }
  if (Room_5.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r5, message4, strlen(message4));
  write(r5, rooms[Room_5.c5], strlen(rooms[Room_5.c5]));
  }
  if (Room_5.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r5, message5, strlen(message5));
  write(r5, rooms[Room_5.c6], strlen(rooms[Room_5.c6]));
  }
  write(r5, type, strlen(type));
  write(r5,room_types[4],strlen(room_types[4]));
  close(r5);

  int r6;
  r6 = open(F, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  write(r6, name, strlen(name));
  write(r6,rooms[6],strlen(rooms[6]));
  write(r6, message, strlen(message));
  write(r6, rooms[Room_6.c1], strlen(rooms[Room_6.c1]));
  write(r6, message1, strlen(message1));
  write(r6, rooms[Room_6.c2], strlen(rooms[Room_6.c2]));
  write(r6, message2, strlen(message2));
  write(r6, rooms[Room_6.c3], strlen(rooms[Room_6.c3]));
  if (Room_6.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r6, message3, strlen(message3));
  write(r6, rooms[Room_6.c4], strlen(rooms[Room_6.c4]));
  }
  if (Room_6.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r6, message4, strlen(message4));
  write(r6, rooms[Room_6.c5], strlen(rooms[Room_6.c5]));
  }
  if (Room_6.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r6, message5, strlen(message5));
  write(r6, rooms[Room_6.c6], strlen(rooms[Room_6.c6]));
  }
  write(r6, type, strlen(type));
  write(r6,room_types[5],strlen(room_types[5]));
  close(r6);

 int r7;
  r7 = open(G, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  write(r7, name, strlen(name));
  write(r7,rooms[7],strlen(rooms[7]));
  write(r7, message, strlen(message));
  write(r7, rooms[Room_7.c1], strlen(rooms[Room_7.c1]));
  write(r7, message1, strlen(message1));
  write(r7, rooms[Room_7.c2], strlen(rooms[Room_7.c2]));
  write(r7, message2, strlen(message2));
  write(r7, rooms[Room_7.c3], strlen(rooms[Room_7.c3]));
  if (Room_7.c4 != 0){
  char message3[] = "\nCONNECTION 4: ";
  write(r7, message3, strlen(message3));
  write(r7, rooms[Room_7.c4], strlen(rooms[Room_7.c4]));
  }
  if (Room_7.c5 != 0){
  char message4[] = "\nCONNECTION 5: ";
  write(r7, message4, strlen(message4));
  write(r7, rooms[Room_7.c5], strlen(rooms[Room_7.c5]));
  }
  if (Room_7.c6 != 0){
  char message5[] = "\nCONNECTION 6: ";
  write(r7, message5, strlen(message5));
  write(r7, rooms[Room_7.c6], strlen(rooms[Room_7.c6]));
  }
  write(r7, type, strlen(type));
  write(r7,room_types[6],strlen(room_types[6]));
  close(r7);

/* Prints out the various connections across all rooms
 printf("\nRoom1 %d Connections: %d %d %d %d %d %d",Room_1.count,Room_1.c1,Room_1.c2,Room_1.c3,Room_1.c4,Room_1.c5,Room_1.c6);
 printf("\nRoom2 %d Connections: %d %d %d %d %d %d",Room_2.count,Room_2.c1,Room_2.c2,Room_2.c3,Room_2.c4,Room_2.c5,Room_2.c6);
 printf("\nRoom3 %d Connections: %d %d %d %d %d %d",Room_3.count,Room_3.c1,Room_3.c2,Room_3.c3,Room_3.c4,Room_3.c5,Room_3.c6);
 printf("\nRoom4 %d Connections: %d %d %d %d %d %d",Room_4.count,Room_4.c1,Room_4.c2,Room_4.c3,Room_4.c4,Room_4.c5,Room_4.c6);
 printf("\nRoom5 %d Connections: %d %d %d %d %d %d",Room_5.count,Room_5.c1,Room_5.c2,Room_5.c3,Room_5.c4,Room_5.c5,Room_5.c6);
 printf("\nRoom6 %d Connections: %d %d %d %d %d %d",Room_6.count,Room_6.c1,Room_6.c2,Room_6.c3,Room_6.c4,Room_6.c5,Room_6.c6);
 printf("\nRoom7 %d Connections: %d %d %d %d %d %d",Room_7.count,Room_7.c1,Room_7.c2,Room_7.c3,Room_7.c4,Room_7.c5,Room_7.c6);
*/

  return 0;

}