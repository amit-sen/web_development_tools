## HTML Project Structure (HPS)
HPS is a simple CLI based tool. It's generate your web development project structure.
    
    Project_name (folder)
    │   index.html
    │
    ├───assets (folder)
    │       favicon.svg
    │
    ├───css (folder)
    │       index.css
    │
    └───js (folder)
        index.js

This tool also generates a *favicon.svg* file made 
with the initial of your project name.

*For example my project name is 'myWebsite' so initial is 'm'*

![screensho](https://github.com/amit-sen/web_development_tools/blob/master/screenshot.PNG)

## How to use?

* Clone this repository. 

* Create a folder anywhere in your PC and paste the file *hps.exe (32 bit or 64 bit)*

* Now add this path to hps.exe to your PATH environment variable. Follow this QA : [How to set the path and environment variables in Windows](https://www.computerhope.com/issues/ch000549.htm#1)

* Open CMD type HPS or hps and your project name, press enter. *(i.e. hps <project_name>)*   

**Example:**

	C:\Users\Amit\Desktop\website>hps myWebsite

	Your project name is myWebsite.

	Folder PATH listing
	Volume serial number is 000F-00AB
	C:\USERS\AMIT\DESKTOP\WEBSITE\MYWEBSITE
	│   index.html
	│
	├───assets
	│       favicon.svg
	│
	├───css
	│       index.css
	│
	└───js
	        index.js
          
	HTML Project Structure created successfully..
	C:\Users\Amit\Desktop\website>
  
*index.html*
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="shortcut icon" href="assets/favicon.svg"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>myWebsite</title>
    <link rel="stylesheet" href="css/index.css">
</head>
<body>
    <h1>Hello World</h1>
    <p>myWebsite is ready to build!</p>
</body>
<script src="js/index.js"></script>
</html>
```

*index.css*
```css
h1{
    color:#2196f3;
}
p{
    color:#4caf50;
}
```

*index.js*
```javascript
console.log('index.js is ready..');
```    
