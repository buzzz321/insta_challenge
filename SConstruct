env = Environment()  # Initialize the environment

env.Append(CCFLAGS='-Wall --pedantic')
env.Append(LIBS = ['png'])
env.Program(target = 'insta', source = ["main.cc", "image.cc"])

#lib_target  = "hello"
#lib_sources = ["libhello.c"]

#env.SharedLibrary(target = lib_target, source = lib_sources)

