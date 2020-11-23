import os
import subprocess

print('\n\033[1;36;40mPyComp\n')

pkg = input('Enter package name: \033[0;37;40m')

proc = subprocess.Popen('ls -a', shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, close_fds=True)

filesystem = str(proc.stdout.read()).split('\\n')

if '.asp' not in filesystem:                  
    subprocess.run(['mkdir','.asp'])

builddir = os.getcwd() + '/.asp/' + pkg

path = pkg + '/trunk'

os.chdir('.asp')
    
print('\033[1;32;40mAcquiring pkgbuild...\n')
    
cmd = 'asp checkout ' + pkg
    
getsrc = subprocess.Popen(cmd, shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, close_fds=True)
    
output = str(getsrc.stdout.read()).split()

def install():
    
    if output[0] == 'b\'error:':
        print('\033[1;31;40mPackage not found')
    
    elif output[0] == 'b"fatal:':
        print('\033[1;31;40mPackage directory already exists')
    
    else:
        print('\033[1;33;40mBuild directory >> \033[0;37;40m',builddir)
        
        os.chdir(path)
        
        print('\n\033[1;32;40mStarting compilation')
        
        subprocess.run(['makepkg','-si'])

install()