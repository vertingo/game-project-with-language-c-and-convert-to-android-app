![Image](https://raw.githubusercontent.com/vertingo/Easy_Admin_YouTube_Newsletter_Firebase/master/web/assets/images/github/vertin_go_website.jpg)
### Apporter votre soutien au projet :heart: pour de futures évolutions!
[![GitHub stars](https://img.shields.io/github/stars/vertingo/screenshott.svg?style=social&label=Star)](https://github.com/vertingo/Easy_Admin_YouTube_Newsletter_Firebase.git) [![GitHub forks](https://img.shields.io/github/forks/vertingo/screenshott.svg?style=social&label=Fork)](http://github.com/vertingo/Easy_Admin_YouTube_Newsletter_Firebase/fork) [![GitHub watchers](https://img.shields.io/github/watchers/vertingo/screenshott.svg?style=social&label=Watch)](http://github.com/vertingo/Easy_Admin_YouTube_Newsletter_Firebase) [![GitHub followers](https://img.shields.io/github/followers/vertingo.svg?style=social&label=Follow)](https://github.com/vertingo)
[![Twitter Follow](https://img.shields.io/twitter/follow/Vertin_Go.svg?style=social)](https://twitter.com/Vertin_Go)
[![Facebook](https://img.shields.io/badge/Facebook-vertingo-blue?style=social&logo=facebook)](https://www.facebook.com/vertingo)
[![YouTube Subscribe](https://img.shields.io/youtube/channel/subscribers/UC2g_-ipVjit6ZlACPWG4JvA?style=social)](https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1)


# 🌐 Android Project with C/C++()[App Progress Status](https://img.shields.io/badge/Status-Finished-0520b7.svg?style=plastic)
![App Progress Status](https://img.shields.io/badge/Status-Finished-0520b7.svg?style=plastic)
[![Download](https://img.shields.io/badge/Download-Repo-brightgreen)](https://github.com/vertingo/game-project-with-language-c-and-convert-to-android-app/archive/refs/heads/main.zip)

<!-- BEGIN LATEST DOWNLOAD BUTTON -->
[![Download zip](https://custom-icon-badges.demolab.com/badge/-Download-blue?style=for-the-badge&logo=download&logoColor=white "Download zip")](https://github.com/vertingo/game-project-with-language-c-and-convert-to-android-app/archive/1.0.2.zip)
<!-- END LATEST DOWNLOAD BUTTON -->

You can add C and C++ code to your Android project by placing the code into a cpp directory in your project module. 
When you build your project, this code is compiled into a native library that Gradle can package with your APK. 
Your Java or Kotlin code can then call functions in your native library through the Java Native Interface (JNI). 
If you want to learn more about using the JNI framework, read JNI tips for Android.

Android Studio's default build tool for native libraries is CMake. 
Android Studio also supports ndk-build due to the large number of existing projects that use the build toolkit to compile their native code. 
If you want to import an existing ndk-build library into your Android Studio project, learn how to link Gradle to your native library project. 
However, if you are creating a new native library, you should use CMake.

This page shows you how to set up Android Studio with the necessary build tools, create a new project with C/C++ support, and add new C/C++ files to your project.

If instead you want to add native code to an existing project, you need to follow these steps:

Create new native source files and add them to your Android Studio project.
You can skip this step if you already have native code or want to import a prebuilt native library.
Configure CMake to build your native source code into a library. You also require this build script if you are importing and linking against prebuilt or platform libraries.
If you have an existing native library that already has a CMakeLists.txt build script, or uses ndk-build and includes an Android.mk build script, you can skip this step.
Configure Gradle by providing a path to your CMake or ndk-build script file. 
Gradle uses the build script to import source code into your Android Studio project and package your native library (the SO file) into the APK.
Once you configure your project, you can access your native functions from Java or Kotlin code using the JNI framework. 
To build and run your app, simply click Run run then run app from the menu bar.

Note: If your existing project uses the deprecated ndkCompile tool, you should migrate to using either CMake or ndk-build. 
To learn more, go to the section about how to Migrate from ndkCompile.

Attention experimental Gradle users: Consider migrating to plugin version 2.2.0 or higher, and using CMake or ndk-build to build your native libraries if any of the following apply to you: Your native project already uses CMake or ndk-build; you would rather use a stable version of the Gradle build system; or you want support for add-on tools, such as CCache. Otherwise, you can continue to use the experimental version of Gradle and the Android plugin.

#Download the NDK and build tools

To compile and debug native code for your app, you need the following components:

- The Android Native Development Kit (NDK): a toolset that allows you to use C and C++ code with Android, and provides platform libraries that allow you to 
manage native activities and access physical device components, such as sensors and touch input.
- CMake: an external build tool that works alongside Gradle to build your native library. You do not need this component if you only plan to use ndk-build.
- LLDB: the debugger Android Studio uses to debug native code.

You can install these components using the SDK Manager:

1.From an open project, select Tools > SDK Manager from the menu bar.

2.Click the SDK Tools tab.

3.Check the boxes next to LLDB, CMake, and NDK, as shown in figure 1. 

[Image]
Figure 1. Installing LLDB, CMake, and the NDK from the SDK Manager.

Click Apply, and then click OK in the pop-up dialog.
When the installation is complete, click Finish, and then click OK.

#Use CMake 3.6.0 or 3.10.2

The SDK Manager includes the 3.6.0 forked version of CMake and version 3.10.2. 
Projects that don't set a specific CMake version in build.gradle are built with CMake 3.6.0. 
To use the later included version, specify CMake version 3.10.2 in your module's build.gradle file:

```
android {
    ...
    externalNativeBuild {
        cmake {
            ...
            version "3.10.2"
        }
    }
}
```

While not a best practice, you may specify the CMake version as the minimum version by adding a + to the end of the build.gradle entry, such as 3.10+ or 3+.

#Use a custom CMake version

If you want to use a CMake version 3.7 or higher that is not included by the SDK Manager, follow these steps:

Download and install CMake 3.7 or higher from the official CMake website.
Specify the CMake version you want Gradle to use in your module's build.gradle file:

```
android {
    ...
    externalNativeBuild {
        cmake {
            ...
            version "cmake-version"
        }
    }
}
```

Either add the path to the CMake installation to your PATH environment variable or include it in your project's local.properties file, as shown below. 
If Gradle is unable to find the version of CMake you specified in your build.gradle file, you get a build error.

# If you set this property, Gradle no longer uses PATH to find CMake.
cmake.dir="path-to-cmake"
If you don't already have the Ninja build system installed on your workstation, go to the official Ninja website, and download and install the latest version of Ninja available for your OS. 
Make sure to also add the path to the Ninja installation to your PATH environment variable.

#Create a new project with C/C++ support

Creating a new project with support for native code is similar to creating any other Android Studio project, but there is an additional step:

In the Choose your project section of the wizard, select the Native C++ project type.
Click Next.
Complete all other fields in the next section of the wizard.
Click Next.
In the Customize C++ Support section of the wizard, you can customize your project with the C++ Standard field. 
Use the drop-down list to select which standardization of C++ you want to use. Selecting Toolchain Default uses the default CMake setting.
Click Finish.
After Android Studio finishes creating your new project, open the Project pane from the left side of the IDE and select the Android view. 
As shown in figure 2, Android Studio adds the cpp group:

Illustrations below but just make sure that the path to your project doesn't contain white space because it could cause problem to build with NDK!
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture5.png" width="500" height="450"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture6.png" width="500" height="450"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture7.png" width="500" height="450"/></a>
</p>
<hr>



Figure 2. Android view groups for your native sources and external build scripts.

Note: This view does not reflect the actual file hierarchy on disk, but groups similar files to simplify navigating your project.

The cpp group is where you can find all the native source files, headers, build scripts for CMake or ndk-build, and prebuilt libraries that are a part of your project. 
For new projects, Android Studio creates a sample C++ source file, native-lib.cpp, and places it in the src/main/cpp/ directory of your app module. 
This sample code provides a simple C++ function, stringFromJNI(), that returns the string "Hello from C++". 
You can learn how to add additional source files to your project in the section about how to Create new native source files.

Similar to how build.gradle files tell Gradle how to build your app, CMake and ndk-build require a build script to know how to build your native library. 
For new projects, Android Studio creates a CMake build script, CMakeLists.txt, and places it in your module’s root directory. 
To learn more about the contents of this build script, read Configure CMake.

#Build and run the sample app


Before executing the project we need to build the library libnative-lib.so with command make
Don't worry these commands are automatically executed when you launch your app but if the 
path to your project contain white spaces as i mentioned above it could cause problem to executed 
make commands! Below its just an example of what is executed automatically when you launch the
app, once again if everything is good for you, your path doesn't contain white spaces make commands
will be executed properly when you launch your app!  

```
make --build  path
```

Verify that libnative-lib.so is inside the APK by going to Build -> Analyse APK

<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture3.png" width="400" height="300"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture4.png" width="500" height="450"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture2.png" width="950" height="250"/></a>
</p>
<br>

When you click Run run then run app from the menu bar, Android Studio builds and launches an app that displays the text "Hello from C++" on your Android device or emulator. 
The following overview describes the events that occur in order to build and run the sample app:

1.Gradle calls upon your external build script, CMakeLists.txt.

2.CMake follows commands in the build script to compile a C++ source file, native-lib.cpp, into a shared object library and names it libnative-lib.so, which Gradle then packages into the APK.

3.During runtime, the app's MainActivity loads the native library using System.loadLibrary(). The library’s native function, stringFromJNI(), is now available to the app.

<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture11.png" width="910" height="227"/></a>
</p>
<hr>
We only just have to declare the prototype of the method we want to reuse form our cpp-native-lib:
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture12.png" width="682" height="118"/></a>
</p>
<hr>
And to finish an example of how to use it:
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture13.png" width="1124" height="78"/></a>
</p>
<hr>

4.MainActivity.onCreate() calls stringFromJNI(), which returns "Hello from C++", and uses it to update the TextView.

Note: Instant Run is not compatible with components of your project written in native code.

If you want to verify that Gradle packages the native library in the APK, you can use the APK Analyzer:

1.Select Build > Build Bundles(s) / APK(s) > Build APK(s)

2.Select Build > Analyze APK.

3.Select the APK from the app/build/outputs/apk/ directory and click OK.

4.As shown in figure 3, you can see libnative-lib.so in the APK Analyzer window under lib/<ABI>/. 

Figure 3. Locating a native library using the APK Analyzer.

<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture3.png" width="400" height="300"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture4.png" width="500" height="450"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture2.png" width="950" height="250"/></a>
</p>
<hr>

Tip: If you want to experiment with other Android apps that use native code, click File > New > Import Sample and select a sample project from the Ndk list.

#Create new C/C++ source files

To add new C/C++ source files to an existing project, proceed as follows:

1.If you don't already have a cpp/ directory in the main source set of your app, create one as follows:
	- Open the Project pane from the left side of the IDE and select the Project view from the drop-down menu.
	- Navigate to your-module > src, right-click on the main directory, and select New > Directory.
	- Enter cpp as the directory name and click OK.
	
2.Right-click on the cpp/ directory and select New > C/C++ Source File.
3.Enter a name for your source file, such as native-lib.
4.From the Type drop-down menu, select the file extension for your source file, such as .cpp.
	- You can add other file types to the drop-down menu, such as .cxx or .hxx, by clicking Edit File Types  . In the C/C++ dialog box that pops up, select another file extension from the Source Extension and Header Extension drop-down menus and click OK.
5.If you also want to create a header file, check the Create an associated header checkbox.
6.Click OK.

After you add new C/C++ files to you project, you still need to configure CMake to include them in your native library.

#Migrate from ndkCompile

If you're using the deprecated ndkCompile, you should migrate to using either CMake or ndk-build. Because ndkCompile generates an intermediate Android.mk file for you, migrating to ndk-build may be a simpler choice.

To migrate from ndkCompile to ndk-build, proceed as follows:

Compile your project with ndkCompile at least once by selecting Build > Make Project. This generates the Android.mk file for you.
Locate the auto-generated Android.mk file by navigating to project-root/module-root/build/intermediates/ndk/debug/Android.mk.
Relocate the Android.mk file to some other directory, such as the same directory as your module-level build.gradle file. This makes sure that Gradle doesn't delete the script file when running the clean task.
Open the Android.mk file and edit any paths in the script such that they are relative to the current location of the script file.
Link Gradle to the Android.mk file .
Disable ndkCompile by opening the build.properties file and removing the following line:
// Remove this line
android.useDeprecatedNdk = true
Apply your changes by clicking Sync Project   in the toolbar.


#Android Musical Game Oboe

Prerequisites:
- Android Studio 3.0.0 or above
- NDK and Build Tools installed
- An Android device running Android Jelly Bean (API level 16) or above for testing. Pixel devices are best for low latency audio.
- Some knowledge of C++ is helpful but not required

```
git clone https://github.com/google/oboe 

cd oboe

git checkout io18codelab (Create your own branch)
```

During the tutorial it can be useful to refer to the final version of the code which is stored in the master branch.
Android Studio makes it easy to compare changes across branches.

Type in a command prompt to learn git emplacement: which git
Enable VCS by making sure git path is well informed in File -> Settings -> Version Control -> Git

<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture.png" width="600" height="450"/></a>
</p>
<hr>

Now you can compare your code with code in the master branch.

Click on the current branch in the bottom right corner
Go to master->Compare

<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture10.png" width="300" height="250"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture9.png" width="1000" height="450"/></a>
</p>
<hr>
<p align="center">
<a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/Android_Game_Project_With_LanguageC/master/images/capture8.png" width="1000" height="450"/></a>
</p>
<hr>

```
SoundRecording *mClap{nullptr};
```

```
mClap = SoundRecording::loadFromAssets(mAssetManager, "CLAP.raw");
```

```
AudioStreamBuilder builder;
    builder.setFormat(AudioFormat::I16);
    builder.setChannelCount(2);
    builder.setSampleRate(48000);
```

```
class Game : public AudioStreamCallback {
```

```
DataCallbackResult
    onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) override;
```

```
DataCallbackResult Game::onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) {
    mClap->renderAudio(static_cast<int16_t *>(audioData), numFrames);
    return DataCallbackResult::Continue;
}
```

```
builder.setCallback(this);
```

```
// Open the stream
Result result = builder.openStream(&mAudioStream);
if (result != Result::OK)
{
        LOGE("Failed to open stream. Error: %s", convertToText(result));
}

// Start the stream
result = mAudioStream->requestStart();
if (result != Result::OK)
{
       LOGE("Failed to start stream. Error: %s", convertToText(result));
}
```

```
mClap->setPlaying(true);
```

<hr>
<p align="center">
  <a href="https://www.youtube.com/channel/UC2g_-ipVjit6ZlACPWG4JvA?sub_confirmation=1"><img src="https://raw.githubusercontent.com/vertingo/easy-admin-youtube-newsletter-firebase/master/web/assets/images/reseaux-sociaux/youtube2.png" width="400" height="250"/></a>
  <a href="https://www.facebook.com/vertingo/"><img src="https://raw.githubusercontent.com/vertingo/easy-admin-youtube-newsletter-firebase/master/web/assets/images/reseaux-sociaux/rejoins_nous.png" width="400" height="250"/></a>
</p>
<hr>
