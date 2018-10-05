# Adding Braindigit to the PATH
## What is the PATH?
The PATH is a list of locations where the computer looks if it can't find a program in the current directory. This makes executing programs far
easier, as you don't need to navigete to the directory it is stored in every time you want to execute it.

## Adding Braindigit to the PATH
### Windows
Search for 'edit the system environment variables' in the start menu and click on this entry:

![Edit the system environment variables](https://github.com/Dandigit/braindigit/raw/master/docs/img/add-to-path.PNG)

A popup panel titled "System Properties" will appear. At the bottom of it, just above the OK, Cancel and Apply buttons is a button labelled 
"Environment Variables" - click on it. Another popup will appear, this time titled "Environment Variables". There will be two fields. In the
top field, labelled "User variables for <username>", double click on the entry named "Path".
  
![Path popup box](https://github.com/Dandigit/braindigit/raw/master/docs/img/path-field-entry.PNG)

Yet another popup will open (don't worry, this is the last one) containing a list of directories.

![List of directories](https://github.com/Dandigit/braindigit/raw/master/docs/img/path-variable-popup.PNG)

Click the "New" button in the sidebar, and enter the path to the folder containing your Braindigit.exe file in the text box that appears, e.g:
```
C:\The\Best\Program\Ever (contains Braindigit.exe)
```
After you've done that, hit Enter, then click OK on all of the popups until they are gone. If you'd like to check that you didn't stuff something up, open a Command Prompt window and type
```
braindigit -v
```
If you don't get version information from Braindigit, you've done it wrong and need to start again.

### macOS
Open a Terminal window and enter the following:
```
sudo nano /etc/paths
```
Enter your password when prompted. A text file will open in Nano containing a list of directories. Create a new line, then enter the path
to the folder containing Braindigit, e.g:
```
/Users/dan/Braindigit
```
Hit Ctrl+X and then press Y to exit Nano and save the file. If you'd like to check that you didn't stuff something up, open a Terminal window and type:
```
braindigit -v
```
If you don't get version information from Braindigit, you've done it wrong and need to start again.

### Linux
Run the following command:
```
sudo nano ~/.profile
```
Enter your password when prompted. A text file will open in Nano containing a list of directories. Create a new line, then enter:
```
export PATH="/path/to/braindigit:$PATH"
```
where `/path/to/braindigit` is the directory containing the Braindigit executable. Hit Ctrl+X and then press Y to exit Nano and save the file. If you'd like to check that you didn't stuff something up, run:
```
braindigit -v
```
If you don't get version information from Braindigit, you've done it wrong and need to start again.
