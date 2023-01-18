add_executable(RecursiveDescentTest
               RecursiveDescent.test.cpp
               ../src/Parser.cpp
               ../src/Parser.h
               ../src/Descent/Common/NonTerminalSymbols.h
               ../src/Descent/Common/TerminalSymbols.h
               ../src/Descent/Common/IFunction.cpp
               ../src/Descent/Common/IFunction.h
               ../src/Descent/Common/Utils.h
               ../src/Descent/Prog.h
               ../src/Descent/Type.h
               ../src/Descent/Var.h
               ../src/Descent/Exp.h
               ../src/Descent/T.h
               ../src/Descent/F.h
               ../src/Descent/Listst.h
               ../src/Descent/Write.h
               ../src/Descent/Read.h
               ../src/Descent/Assign.h)

target_link_libraries(RecursiveDescentTest PUBLIC catch2)
add_test(NAME RecursiveDescentTest COMMAND RecursiveDescentTest)
