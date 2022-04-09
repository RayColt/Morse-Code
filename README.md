# Morse Code
current version: 1.16

<br>
Please change the Icon line below in all three Forms into your own local url's to have an icon in the left corner
<br> and even more important to have no errors or exceptions while opening the form creator of the extension "C++/CLR Windows Forms for Visual Studio 2019". Install this extension before opening the sln file in Visual Studio 2019.<br><br>
so change <br><code>
this-&gt;Icon = (cli::safe_cast&lt;System::Drawing::Icon^&gt;(resources-&gt;GetObject(L&quot;$this.Icon&quot;)));</code><br>
into tour own url's, in Form1.cpp, Form2.cpp, Form3.cpp<br><code>
this-&gt;Icon = gcnew System::Drawing::Icon(L&quot;D:\\Repos\\Morse Code\\Morse Code\\app.ico&quot;);</code>

<br><br>
A windows version of <a href="https://github.com/RayColt/morse">my console C++ morse app</a>. Listen to homemade morse files with, for example, the android ggmorse app:
<br>
<a href="https://github.com/RayColt/morse/tree/master/cpp"><img src=https://github.com/RayColt/morse/blob/master/cpp/colt-morse.jpg></a>  
