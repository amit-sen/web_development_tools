#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h>

void SetColor(int ForgC) {
  WORD wColor;
  //This handle is needed to get the current background attribute
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  //csbi is used for wAttributes word

  if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
    //To mask out all but the background attribute, and to add the color
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
}

int main() {
  char projName[100] = "";
  char cmd[100] = "";
//get project name
  SetColor(3);
  printf("project name:");
  gets(projName);
//

  strcpy(cmd, "mkdir "); // set cmd = <cd>
  strcat(cmd, projName); //now cmd = mkdir <projaectName>
  system(cmd); //exicute command

//create all require folders(assets, css, js)
  strcpy(cmd, "cd ");
  strcat(cmd, projName);
  strcat(cmd, " && mkdir assets");
  system(cmd);

  strcpy(cmd, "cd ");
  strcat(cmd, projName);
  strcat(cmd, " && mkdir css");
  system(cmd);

  strcpy(cmd, "cd ");
  strcat(cmd, projName);
  strcat(cmd, " && mkdir js");
  system(cmd);
//

//create favicon.svg
  strcpy(cmd, "");
  strcat(cmd, projName);
  strcat(cmd, "/assets/favicon.svg");
  FILE * fpSVG;
  fpSVG = fopen(cmd, "w");
  fprintf(fpSVG, "<svg version=%c1.1%c id=%cLayer_1%c xmlns=%chttp://www.w3.org/2000/svg%c xmlns:xlink=%chttp://www.w3.org/1999/xlink%c x=%c0px%c y=%c0px%c viewBox=%c0 0 203.8 203.8%c style=%cenable-background:new 0 0 203.8 203.8;%c xml:space=%cpreserve%c> <circle fill=%c#2196f3%c cx=%c100%c cy=%c100%c r=%c100%c></circle> <text x=%c100%c y=%c105%c fill=%cwhite%c font-family=%cArial%c font-weight=%cBold%c font-size = %c130%c text-anchor=%cmiddle%c alignment-baseline=%cmiddle%c>%c</text></svg>",34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34 ,34, 34,* projName);
  fclose(fpSVG);
//

//create index.css
  strcpy(cmd, "");
  strcat(cmd, projName);
  strcat(cmd, "/css/index.css");
  FILE * fpCss;
  fpCss = fopen(cmd, "w");
  fclose(fpCss);
//

//create index.js
  strcpy(cmd, "");
  strcat(cmd, projName);
  strcat(cmd, "/js/index.js");
  FILE * fpJs;
  fpJs = fopen(cmd, "w");
  fclose(fpJs);
//

//create index.html
  strcpy(cmd, "");
  strcat(cmd, projName);
  strcat(cmd, "/index.html");
  FILE * fpHtml;
  fpHtml = fopen(cmd, "w");
  
//index.html text content
  fprintf(fpHtml, "<!DOCTYPE html>\n");
  fprintf(fpHtml, "<html lang=%cen%c>\n", 34, 34);
  fprintf(fpHtml, "<head>\n");
  fprintf(fpHtml, "    <meta charset=%cUTF-8%c>\n", 34, 34);  
  fprintf(fpHtml, "    <link rel=%cshortcut icon%c href=%cassets/favicon.svg%c/>\n", 34, 34, 34, 34);
  fprintf(fpHtml, "    <meta name=%cviewport%c content=%cwidth=device-width, initial-scale=1.0%c>\n", 34, 34, 34, 34);
  fprintf(fpHtml, "    <title>%s</title>\n", projName);
  fprintf(fpHtml, "    <link rel=%cstylesheet%c href=%ccss/index.css%c>\n", 34, 34, 34, 34);
  fprintf(fpHtml, "</head>\n");
  fprintf(fpHtml, "<body>\n");
  fprintf(fpHtml, "    <h1>Hello World</h1>\n");
  fprintf(fpHtml, "    <p>Your project: %s is ready to build!</p>\n", projName);
  fprintf(fpHtml, "</body>\n");
  fprintf(fpHtml, "<script src=%cjs/index.js%c></script>\n", 34, 34);
  fprintf(fpHtml, "</html>");
//
  fclose(fpHtml);
//

//final tree command exicute
  strcpy(cmd, "tree ");
  strcat(cmd, projName);
  strcat(cmd, " /F");
  SetColor(6);
  system(cmd);
  SetColor(2);
  printf("HTML structure created successfully..");
  strcpy(cmd, "cd ");
  strcat(cmd, projName);
  //strcat(cmd," && index.html");
  system(cmd);
  SetColor(7);
  exit(0);
  return 0;
//
}
