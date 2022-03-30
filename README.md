# SEMPERIDEM

Hello and welcome to my game engine "Semperidem", which means "always the same".
It is written in C++ and it is my first attempt creating a game engine.

I followed the instructions of "The Cherno" on [Youtube](https://www.youtube.com/watch?v=JxIZbV_XjAs&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT). I watched all videos which were recommended in our Moodle course plus the videos about Layers, OpenGL, ImGui and ImGui Events.

## Setup
To build and compile this project you will need **Visual Studio 2019**.
To install the engine you have to clone this repository to your computer with **git clone --recursive \<path to repo\>**. 
Then you have to execute the following steps:
* Execute the GenerateProjects.bat script
* Open the solution Semperidem.sln in Visual Studio 2019.
* Build, compile and start the engine.

After you compiled it once, you will find an executable-file in **\bin\Debug-windows-x86_64\Sandbox**.

## What you will see
When you execute the executable-file or you start the engine in Visual Studio 2019 a console and a window will be opened.
The window should have a size of 1280 x 720 and the background color will be pink.
In the console you will see:
* three test logging statements which will be displayed before the engine is starting
* a message which indicates that the engine started
* logs of events, which will either be KeyEvents, MouseEvents, ApplicationEvents, or logs of an example layer called Semperidem_Example_Layer. This layer will be called every frame (OnUpdate).

In the window you will see:
* a pink background and a demo window of Imgui, which you can move around, you can click things on it and you can type characters
* general window (with pink background) can also be resized

When you want to shutdown the engine, just click the cross on the windwo tab.

![Window](https://user-images.githubusercontent.com/91611690/160892055-8b856a7e-8b10-4984-a337-b8e2ca905a17.PNG)

![Console](https://user-images.githubusercontent.com/91611690/160697314-a2be4af1-fbb8-478d-ba1b-0d1389935d4e.PNG)

## Libraries or Tools
I used the following libraries:
* [spdlog](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbURjMm9vSUlXenZ1ay1KcUVmY0VrZ0hjbUU4UXxBQ3Jtc0ttdHZYcXZxYXktRWhJNmViXzl3LTFkUDZiNUZfa2NZZjlqSDUtaHRrNDJfeF9RYk5vQ0tlWnU0QTVocVNfS080REYxcmdTTXE1bUFsOEx2bE1yYXpnbHJTWXlaX0JvRnR5cmt0M3RIU294ci1IYUVPbw&q=https%3A%2F%2Fgithub.com%2Fgabime%2Fspdlog)
* [GLFW](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqblRyd05nTWk5Q0lvN0tFVFczMmpnT19YZG15QXxBQ3Jtc0tudmI3ZzBkdHpuUmpYQnU1eW5iUVRPdUp5MWlyVGxnODBfWVkxVUdpRl85TG52ekxFNEV1aXBsZUZsU3k3NXdwQ3VoM1dCVUYzZDlYWEZyODFvSUFYVlhRS3FhcVdqZlQ3cTJNUlJmN1pxZmY4NV9Qdw&q=https%3A%2F%2Fgithub.com%2FTheCherno%2FGLFW)
* [GLAD](https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbk5jMjFGUnU4UzVKTHNsQUdrRDUwVmFvMHE1UXxBQ3Jtc0tuSGduaGRqQjZvaHM1NkNVcUdmNWpsc0wtTW90OGtVRG1CZTF3RS1SZjNWTDQ0dTM3UDRjZWFOdDlJLWZFbExITlF5THpjSFNhNWhpQS1IUk9iOWFaOEttUlh4bmhuNEoxc0lycFctMkVUeDJSb09xaw&q=https%3A%2F%2Fglad.dav1d.de%2F)
*  [ImGui](https://github.com/TheCherno/imgui)
* Premake
