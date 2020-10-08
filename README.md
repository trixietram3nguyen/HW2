# HW2 - COSC4370
Name: Trixie Tram Nguyen PSID: 1518295

1. Objective: Practice some of the basics of OpenGL.
2. Environment: Run and compile on Visual Studio 2019 on Windows with openGL(GLUT) setup to get the output display. Screenshot the result and saved as png file.
3. Project details: To be able to use basic functions such as glPushMatrix, glPopMatrix, glTranslatef, etc with openGL to display some several required 3D scenes along with 1 creative scene. Fill in the main.cpp source code to complete the assignment such as: cameraposition array initialize, function problem 1, 2, 3, and function to let user switch between problem using keyboard(in my code user can use the key 1, 2, 3 to switch around the scene or q, Q, Esc to exit the scene). Complete display function by fill in the glViewport, gluPerspective, and gluLookAt. Required to use both glutSolidTeapot and glutSolidCube to get the result displayed for problem 1 and 2. 
4. Result: For problem 1 is a ring of teapot that rotating around the center. My result seem to match the requirement result although, it seem to shift up and to the right a little bit. For problem 2 is a stairs step up produced by cubes. My result is about 80-90% match the requirement, although, if look closely you can see that my object tend to lend a little bit forward the viewer. The third problem, I created a X using teapot by playing around with the glTranslatef function with different numbers. Around the X teapots I also displayed some cubes in the up, down, right and left position with the cubes getting bigger as it further away from the center. The smallest cube is placed in the middle.
Reference: https://docs.microsoft.com/en-us/windows/win32/opengl/glulookat
https://stackoverflow.com/questions/23971752/understanding-glpushmatrix-and-glpopmatrix/23971843#:~:text=OpenGL%20keeps%20a%20stack%20of,top%20matrix%20off%20the%20stack.&text=function%20on%20the%20top%20matrix,use%20to%20transform%20their%20data.
https://www.absingh.com/opengl/?fbclid=IwAR0l-iVDrFzq8zDFmMwXNnIDfQXXGdFssrtFWHRrEHzU6OMWvZRfGdiI_Do
and also some help from the classmate to understand how to use some of the functions.
