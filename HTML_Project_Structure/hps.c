#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void hps_help();

void SetColor(int ForgC) {
  WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
  }
}

int main(int argc, char *argv[]) {

  char cmd[100] = "";
  
  if (argc == 1) {
    hps_help(); 
    exit(EXIT_SUCCESS);
    return 0;
  }
  else if (argc == 3 &&(strcmp(argv[1], "--project") == 0 || strcmp(argv[1], "-p") == 0)) {
    //get project name
    SetColor(11);
    printf("\nYour project name is %s.\n\n", argv[2]);

    strcpy(cmd, "mkdir ");// set cmd = <mkdir>
    strcat(cmd, argv[2]); //now cmd = mkdir <projaectName>
    system(cmd); //execute command

    //create all require folders(assets, css, js)
    strcpy(cmd, "cd ");// set cmd = <cd>
    strcat(cmd, argv[2]);
    strcat(cmd, " && mkdir assets");
    system(cmd);

    strcpy(cmd, "cd ");
    strcat(cmd, argv[2]);
    strcat(cmd, " && mkdir css");
    system(cmd);

    strcpy(cmd, "cd ");
    strcat(cmd, argv[2]);
    strcat(cmd, " && mkdir js");
    system(cmd);
    //

    //create favicon.svg
    strcpy(cmd, "");
    strcat(cmd, argv[2]);
    strcat(cmd, "/assets/favicon.svg");
    FILE * fpSVG;
    fpSVG = fopen(cmd, "w");
    fprintf(fpSVG, "<svg version=%c1.1%c id=%cLayer_1%c xmlns=%chttp://www.w3.org/2000/svg%c xmlns:xlink=%chttp://www.w3.org/1999/xlink%c x=%c0px%c y=%c0px%c viewBox=%c0 0 203.8 203.8%c style=%cenable-background:new 0 0 203.8 203.8;%c xml:space=%cpreserve%c> <circle fill=%c#2196f3%c cx=%c100%c cy=%c100%c r=%c100%c></circle> <text x=%c100%c y=%c105%c fill=%cwhite%c font-family=%cArial%c font-weight=%cBold%c font-size = %c130%c text-anchor=%cmiddle%c alignment-baseline=%cmiddle%c>%c</text></svg>", 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34 , 34, 34, * argv[2]);
    fclose(fpSVG);
    //

    //create index.css
    strcpy(cmd, "");
    strcat(cmd, argv[2]);
    strcat(cmd, "/css/index.css");
    FILE * fpCss;
    fpCss = fopen(cmd, "w");
    fprintf(fpCss, "h1{\n    color:#2196f3;\n}\np{\n    color:#4caf50;\n}");
    fclose(fpCss);
    //

    //create index.js
    strcpy(cmd, "");
    strcat(cmd, argv[2]);
    strcat(cmd, "/js/index.js");
    FILE * fpJs;
    fpJs = fopen(cmd, "w");
    fprintf(fpJs, "console.log('index.js is ready..');");
    fclose(fpJs);
    //

    //create index.html
    strcpy(cmd, "");
    strcat(cmd, argv[2]);
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
    fprintf(fpHtml, "    <title>%s</title>\n", argv[2]);
    fprintf(fpHtml, "    <link rel=%cstylesheet%c href=%ccss/index.css%c>\n", 34, 34, 34, 34);
    fprintf(fpHtml, "</head>\n");
    fprintf(fpHtml, "<body>\n");
    fprintf(fpHtml, "    <h1>Hello World</h1>\n");
    fprintf(fpHtml, "    <p>%s is ready to build!</p>\n", argv[2]);
    fprintf(fpHtml, "</body>\n");
    fprintf(fpHtml, "<script src=%cjs/index.js%c></script>\n", 34, 34);
    fprintf(fpHtml, "</html>");
    //
    fclose(fpHtml);
    //

    //final tree command execute
    strcpy(cmd, "tree ");
    strcat(cmd, argv[2]);
    strcat(cmd, " /F");
    SetColor(14);
    system(cmd);
    SetColor(10);
    printf("HTML Project Structure created successfully..");
    strcpy(cmd, "cd ");
    strcat(cmd, argv[2]);
    //strcat(cmd," && index.html"); for open index.html file in browser
    system(cmd);
    SetColor(7);
    exit(EXIT_SUCCESS);
    return 0;
  }

  else if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "--h") == 0) {
    hps_help();
  }

  else if ( argc == 3 && (strcmp(argv[1], "--add") == 0 || strcmp(argv[1], "-a") == 0)) {

    SetColor(10);
    //create all require folders(css, js)
    mkdir("css");
    mkdir("js");
    //

    //create index.html
    strcat(cmd, argv[2]);
    strcat(cmd, ".html");

    FILE * fpHtml;
    fpHtml = fopen(cmd, "w");

    //index.html text content
    fprintf(fpHtml, "<!DOCTYPE html>\n");
    fprintf(fpHtml, "<html lang=%cen%c>\n", 34, 34);
    fprintf(fpHtml, "<head>\n");
    fprintf(fpHtml, "    <meta charset=%cUTF-8%c>\n", 34, 34);
    fprintf(fpHtml, "    <link rel=%cshortcut icon%c href=%cassets/favicon.svg%c/>\n", 34, 34, 34, 34);
    fprintf(fpHtml, "    <meta name=%cviewport%c content=%cwidth=device-width, initial-scale=1.0%c>\n", 34, 34, 34, 34);
    fprintf(fpHtml, "    <title>%s</title>\n", argv[2]);

    strcpy(cmd, "");
    strcat(cmd, argv[2]);
    strcat(cmd, ".css");

    fprintf(fpHtml, "    <link rel=%cstylesheet%c href=%ccss/%s%c>\n", 34, 34, 34, cmd, 34);
    fprintf(fpHtml, "</head>\n");
    fprintf(fpHtml, "<body>\n");
    fprintf(fpHtml, "    <p>%s is ready to build!</p>\n", argv[2]);
    fprintf(fpHtml, "</body>\n");

    strcpy(cmd, "");
    strcat(cmd, argv[2]);
    strcat(cmd, ".js");

    fprintf(fpHtml, "<script src=%cjs/%s%c></script>\n", 34, cmd, 34);
    fprintf(fpHtml, "</html>");
    //

    fclose(fpHtml);
    //

    //create file.js
    strcpy(cmd, "");
    strcat(cmd, "js/");
    strcat(cmd, argv[2]);
    strcat(cmd, ".js");

    FILE * fpJs;
    fpJs = fopen(cmd, "w");
    fprintf(fpJs, "console.log('ready..');");
    fclose(fpJs);
    //

    //create file.css
    strcpy(cmd, "");
    strcat(cmd, "css/");
    strcat(cmd, argv[2]);
    strcat(cmd, ".css");

    FILE * fpCss;
    fpCss = fopen(cmd, "w");
    fprintf(fpCss, "p{\n    color:#4caf50;\n}");
    fclose(fpCss);
    //
    printf("%s.html\n%s.css\n%s.js\nadded successfully..\n\n", argv[2], argv[2], argv[2]);
    system("tree/F");
    SetColor(7);
    exit(EXIT_SUCCESS);
    return 0;
  }

  else if ((strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)) {
    printf("\n hps 17.08.20\n");
    SetColor(7);
  }

  else {
    hps_help();
    exit(EXIT_SUCCESS);
    SetColor(7);
    return 0;
  }
    exit(EXIT_SUCCESS);
    SetColor(7);
    return 0;
}

void hps_help() {
  SetColor(11);
  printf("\n\n\nHelp\n\n");
  printf("hps --project or -p <project_name>\n                                   create project folder.\n\n");
  printf("hps --add or -a <only_file_name>\n                                   add (.html, .css and .js) files into its corresponding directory,\n                                   enter file name without extension.\n\n");
  printf("hps --help or -h\n                                   print help text.\n\n");
  printf("hps --version or -v\n                                   print program version.\n\n");
  SetColor(7);
}
