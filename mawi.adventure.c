#define  _GNU_SOURCE
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

// function to find latest modified directory
char* findLatestDirectory(char* path, char* prefix){
  struct stat dirStat;
  char directoryName[256];
  char* latestDirName;

  // Open the directory
  DIR* currDir = opendir(path);
  struct dirent *aDir;
  time_t lastModifTime;
  int i = 0;

  /* The data returned by readdir() may be overwritten by subsequent calls to  readdir()  for  the  same  directory stream. So we will copy the name of the directory to the variable directoryName
  */ 
  while((aDir = readdir(currDir)) != NULL){
    // Use strncmp to check if the directory name matches the prefix
    if(strncmp(prefix, aDir->d_name, strlen(prefix)) == 0){
      stat(aDir->d_name, &dirStat);
      // Check to see if this is the directory with the latest modification time
      if(i == 0 || difftime(dirStat.st_mtime, lastModifTime) > 0){
        lastModifTime = dirStat.st_mtime;
        memset(directoryName, '\0', sizeof(directoryName));
        strcpy(directoryName, aDir->d_name);
      }
      i++;
    }
  }
  latestDirName = malloc(sizeof(char) * (strlen(directoryName) + 1));
  strcpy(latestDirName, directoryName);

  closedir(currDir);
  return latestDirName;
}

// array of the hard-coded room names(10)
const char* rooms[] = {"Sun","Moon","Cloud","Wind","Earth","Ground","Air","Heaven","Land","Ocean"};
// empty array to be filled 
const char* dir_room[10]= {};

int main(void) {
//gets the latest dir
char* latestDir = findLatestDirectory(".", "mawi.rooms.");
//creates 10 chars of the rooms 
char A[100];
char B[100];
char C[100];
char D[100];
char E[100];
char F[100];
char G[100];
char H[100];
char I[100];
char J[100];
//copies the directory path to directory char 
char directory[100];
strcpy(directory,"./");
strcat(directory,latestDir);
strcat(directory,"/");
//combines the directory path along with the room names 
strcpy(A,directory);
strcpy(B,directory);
strcpy(C,directory);
strcpy(D,directory);
strcpy(E,directory);
strcpy(F,directory);
strcpy(G,directory);
strcpy(H,directory);
strcpy(I,directory);
strcpy(J,directory);
strcat(A, rooms[0]);
strcat(B, rooms[1]);
strcat(C, rooms[2]);
strcat(D, rooms[3]);
strcat(E, rooms[4]);
strcat(F, rooms[5]);
strcat(G, rooms[6]);
strcat(H, rooms[7]);
strcat(I, rooms[8]);
strcat(J, rooms[9]);
// adds to the empty array with newly concatenated dir path and room name 
dir_room[0] = A;
dir_room[1] = B;
dir_room[2] = C;
dir_room[3] = D;
dir_room[4] = E;
dir_room[5] = F;
dir_room[6] = G;
dir_room[7] = H;
dir_room[8] = I;
dir_room[9] = J;

//loops through all the rooms and seeks out the start room by reading the file
 int length = strlen(directory) - 10;
  
  for (int i = 0; i < 9; i++) {
  int fd;
  fd = open(dir_room[i],O_RDWR);
   // Reads current room location by seeking after ROOM_NAME:
  char* roomname = malloc(50 * sizeof(char));
  lseek(fd,10,SEEK_CUR);
  read(fd, roomname, strlen(dir_room[i]) - length + 1 );
  //Searches for START_ROOM in the file
  char* roomtype = malloc(50 * sizeof(char));
  lseek(fd,-7,SEEK_END);
  read(fd, roomtype,50);
  char str1[15];
  strcpy(str1,"RT_ROOM");
  int startpoint = strcmp(roomtype,str1);
   //compares START_ROOM strings to see if current opened room file is the start 
  if (startpoint == 0){
  printf("CURRENT LOCATION:%s",roomname);
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
 }


 // Empty steps array holds room name if traversed 
const char* steps[] = {};
// counter used to count number of steps taken 
int count = 0;
// initialize buffer for getline 
 char *buffer = NULL;
  size_t bufsize = 0;
  size_t nread;
  //buffer = (char *)malloc(bufsize * sizeof(char));

// Runs the user interface until game is exited with a return 0. While true, the program will repeat, asking for user to enter a location and open up that room's location until the END_ROOM is found and exits with 0.
while(1){

  printf("WHERE TO? >");
  // getline used to retrieve user input and stores into buffer
  nread = getline(&buffer,&bufsize,stdin);
  //reads the input from user and excludes the newline
  buffer[strcspn(buffer, "\n")] = '\0';

  // strcmp used to compare user input with room names
  int sun_room = strcmp(rooms[0],buffer);
  int moon_room = strcmp(rooms[1],buffer);
  int cloud_room = strcmp(rooms[2],buffer);
  int wind_room = strcmp(rooms[3],buffer);
  int earth_room = strcmp(rooms[4],buffer);
  int ground_room = strcmp(rooms[5],buffer);
  int air_room = strcmp(rooms[6],buffer);
  int heaven_room = strcmp(rooms[7],buffer);
  int land_room = strcmp(rooms[8],buffer);
  int ocean_room = strcmp(rooms[9],buffer);

    // Opens the room file if user input matches correct room name. Same for all rooms that are generated
   if (moon_room == 0){
    // adds Room name to steps array 
    steps[count] = "Moon";
    count = count + 1;
    int fd;
    fd = open(dir_room[1],O_RDWR);
    // Reads the room type from file 
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    // if END_ROOM is found, display ending messages
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.", count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    //loops through steps array to show locations visited
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Moon");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  
  else if (sun_room == 0){
    steps[count] = "Sun";
    count = count + 1;
    int fd;
    fd = open(dir_room[0],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else {
  printf("\nCURRENT LOCATION: Sun");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd); }
  }
  else if (ground_room == 0){
    steps[count] = "Ground";
    count = count + 1;
    int fd;
    fd = open(dir_room[5],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Ground");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  else if (cloud_room == 0){
    steps[count] = "Cloud";
    count = count + 1;
    int fd;
    fd = open(dir_room[2],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Cloud");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  else if (wind_room == 0){
    steps[count] = "Wind";
    count = count + 1;
    int fd;
    fd = open(dir_room[3],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Wind");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn1 = malloc(115 * sizeof(char));
  lseek(fd,10+strlen(conn1),SEEK_CUR);
  read(fd,conn1,115);
  printf("%s\n",conn1);
  close(fd);
  }
  else if (heaven_room == 0){
    steps[count] = "Heaven";
    count = count + 1;
    int fd;
    fd = open(dir_room[7],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Heaven");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  else if (land_room == 0){
    steps[count] = "Land";
    count = count + 1;
    int fd;
    fd = open(dir_room[8],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Land");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  else if (air_room == 0){
    steps[count] = "Air";
    count = count + 1;
    int fd;
    fd = open(dir_room[6],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Air");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  else if (ocean_room == 0){
    steps[count] = "Ocean";
    count = count + 1;
    int fd;
    fd = open(dir_room[9],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS.",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);}
    return 0;
  }else{
    }
  printf("\nCURRENT LOCATION: Ocean");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }
  else if (earth_room == 0){
    steps[count] = "Earth";
    count = count + 1;
    int fd;
    fd = open(dir_room[4],O_RDWR);
    char* roomtype = malloc(50 * sizeof(char));
    lseek(fd,-7,SEEK_END);
    read(fd, roomtype,50);
    char str1[15];
    strcpy(str1,"ND_ROOM");
    char* room1 = strtok(roomtype, " ");
    int endpoint = strcmp(roomtype,str1);
    if (endpoint == 0){  
    printf("\nYOU HAVE FOUND THE END ROOM. CONGRATULATIONS!");
    printf("\nYOU TOOK %d STEPS. ",count);
    printf(" YOUR PATH TO VICTORY WAS:\n");
    for (int i = 0; i < count; i++){
    printf("%s\n",steps[i]);
    };
    return 0;
  }else{
  printf("\nCURRENT LOCATION: Earth");
  printf("\nPOSSIBLE CONNECTIONS: \n");
  char* conn = malloc(50 * sizeof(char));
  lseek(fd,0,SEEK_SET);
  lseek(fd,10+strlen(conn),SEEK_CUR);
  read(fd,roomtype,115);
  printf("%s\n",roomtype);
  close(fd);
  }}
  // if user input does not match room names, displays error message 
 else{
   printf("\nHUH? I DON’T UNDERSTAND THAT ROOM. TRY AGAIN.\n\n");
   
 }
}
  return 0;
}