add_library(libraries SHARED
  turingMachine.cc
  turingMachine.h
  state.cc
  state.h
  transition.cc
  transition.h
  )

target_include_directories(libraries PUBLIC
  .
)