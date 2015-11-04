#ifndef TESTMACROS
#define TESTMACROS


#define TEST(TestCase, TestName)\
void TestCase##_##TestName()


#define TEST_F(TestClass, TestName)\
    class TestClass##_##TestName: public TestClass\
    {\
    public:\
        TestClass##_##TestName():TestClass(#TestClass,#TestName)\
    {\
        SetUp();\
        testExecuter.AddTest(this);\
    }\
    virtual ~TestClass##_##TestName()\
    {\
        TearDown();\
    }\
    void TestCode();\
    };\
        TestClass##_##TestName T_##TestClass##_##TestName;\
    void TestClass##_##TestName::TestCode()

// Macro executing all testcases
#define RUN_ALL_TESTS(withTime)\
    testExecuter.RunAllTests(withTime)

// Przykladowe makra. Mozna dopisac inne jak zajdzie taka potrzeba :)

#define ASSERT_EQ_STL_CONTAINER(actual, expected)\
if(!(actual.size() == expected.size()))\
{\
    result =0;\
    cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
    cout << "Size of:" << #actual << "\n";\
    cout << "Expected:\t" << actual.size() << "\n";\
    cout << "Assertion: " << "= " << "\n";\
    cout << "Actual:\t\t" << expected.size() << "\n";\
}\
else\
{\
    for(unsigned int i = 0; i < actual.size(); i++)\
    {\
        if(actual[i] != expected[i])\
        {\
            result = 0;\
            cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
            cout << "Contents of: " << #actual << " differ from contents of " << #expected << "\n\n";\
            cout << "Index\t|\tActual\t|\tExpected" << endl;\
            for(unsigned int j = 0; j <=i; j++)\
            {\
                cout << j << "\t| \t" << actual[j] << "\t|\t" << expected[j]; \
                if(j!=i)\
                {\
                    cout << endl;\
                }\
            }\
            cout << "\t <----" << endl;\
            break;\
        }\
    }\
}


#define ASSERT_EQ_HEX(actual, expected)\
if(!(actual == expected))\
{\
    result = 0;\
    cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
    cout << hex << showbase;\
    cout << "Value of:  " << #actual << "\n";\
    cout << "Expected:\t" << actual << "\n";\
    cout << "Assertion: " << "= " << "\n";\
    cout << "Actual:\t\t" << expected << "\n";\
    cout << dec << noshowbase;\
}\
else\
{\
    result = result && 1;\
}

#define ASSERT_EQ(actual, expected)\
if(!(actual == expected))\
{\
    result = 0;\
    cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
    cout << "Value of:  " << #actual << "\n";\
    cout << "Actual:    " << actual << "\n";\
    cout << "Assertion: " << "= " << "\n";\
    cout << "Expected:  " << expected << "\n";\
}\
else\
{\
    result = result && 1;\
}

#define ASSERT_NE(actual, expected)\
if(!(actual != expected))\
{\
    result = 0;\
    cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
    cout << "Value of:  " << #actual << "\n";\
    cout << "Actual:    " << actual << "\n";\
    cout << "Assertion: " << "!= " << "\n";\
    cout << "Expected:  " << expected << "\n";\
}\
else\
{\
    result = result && 1;\
}

#define ASSERT_NE_HEX(actual, expected)\
if(!(actual != expected))\
{\
    result = 0;\
    cout << __FILE__ << ":" << __LINE__ << ":" << "FAILURE\n";\
    cout << hex << showbase;\
    cout << "Value of:  " << #actual << "\n";\
    cout << "Actual:    " << actual << "\n";\
    cout << "Assertion: " << "!= " << "\n";\
    cout << "Expected:  " << expected << "\n";\
    cout << dec << noshowbase;\
}\
else\
{\
    result = result && 1;\
}




#endif // TESTMACROS

