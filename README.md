# NitroCppTest-ConDaly

1)Mac Version:

Thhe code for this application was developed on an Apple Mac with Xcode version 8.3. I used the C++ Boost libraries to read in 
the JSON file. The boost libraries can be obtained from the following site:http://www.boost.org/users/history/version_1_63_0.html
To build the project on Xcode simply download the project and files and udate the search path for the Boost header and lib directories by clicking on 
the project name and "Build Settings"-> "Search Path". Locate the include and lib folders on your Mac and update them. For exampe I used 
"/usr/local/Cellar/boost/1.63.0/include" and "/usr/local/Cellar/boost/1.63.0/lib". 
Aslo include the command line argument for the JSON file by clicking on the menu item "Product"->"Scheme"->"Edit Scheme" and adding the path of the JSON file.


2) Windows Version using Visual Studio C++:

This applicationcan will also run on Misrosoft Windows using Visual Studio C++. To do this simply create a "Console Project" and add the header and source files
to the project. Add in the search path for the Boost header and lib files in the "Property Pages" "VC++ Directories" settings.
Also in the "Precompiled Headers" section select "Not using precompiled headers". Also In the Debuggig section of the "Property Pages" 
set the command line arguments to include "data.json". The application should now be ready to build successfully.

