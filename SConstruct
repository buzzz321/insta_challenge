env = Environment()  # Initialize the environment

env.Append(CCFLAGS='-Wall --pedantic -g')
env.Append(LIBS = ['png', 'freeimage'])
env.Program(target = 'insta', source = ["main.cc", "image.cc", "Imagecontrol.cc"])

#lib_target  = "hello"
#lib_sources = ["libhello.c"]

#env.SharedLibrary(target = lib_target, source = lib_sources)

