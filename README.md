## Html Project Structure (HPS)
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

* Download *HPS.exe*.Create a folder anywhere in your computer and paste the file. 

* Now set this directory as the environment variable
path.

* Open CMD type HPS or hps press enter and put your project name.    

**Example:**

	C:\Users\Amit\Desktop\website>hps
	project name:myWebsite
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
          
	HTML structure created successfully..
	C:\Users\Amit\Desktop\website>
  
*index.html*
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel="shortcut icon" href="assets/favicon.svg"/>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>hh</title>
    <link rel="stylesheet" href="css/index.css">
</head>
<body>
    <h1>Hello World</h1>
    <p><span class='project-name'>hh</span> is ready to build!</p>
</body>
<script src="js/index.js"></script>
</html>
```

*index.css*
```css
.project-name{
    color:#2196f3;
}
h1{
    color:#f44336;
}
p{
    color:#4caf50;
}
```

*index.js*
```javascript
console.log('index.js is ready..');

```    
