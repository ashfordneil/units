# Variables
set(SOURCES units.h signalHandling.c signalHandling.h tests.c types.c types.h runtime.c runtime.h)

# Main library
add_library(units STATIC ${SOURCES})

# Install targets
Install(TARGETS units DESTINATION lib)
Install(FILES units.h DESTINATION include)
