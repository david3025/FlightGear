#include "ShuntingYard.h"

#define LEFT_ASSOC 0
#define RIGHT_ASSOC 1 //for ^

typedef map<string, pair< int,int >> OpMap;
typedef vector<string>::const_iterator cv_iter;
typedef string::iterator s_iter;

const OpMap::value_type assocs[] =   
    {  OpMap::value_type( "+", make_pair( 0, LEFT_ASSOC ) ),    
       OpMap::value_type( "-", make_pair( 0, LEFT_ASSOC ) ),      
       OpMap::value_type( "*", make_pair( 5, LEFT_ASSOC ) ),      
       OpMap::value_type( "/", make_pair( 5, LEFT_ASSOC ) ) };

const OpMap opmap( assocs, assocs + sizeof( assocs ) / sizeof( assocs[ 0 ] ) );

bool Shuntingyard::isParenthesis( const string& token)
{        
    
    return token == "(" || token == ")";
}      
const pair< int,int >& tokenToPair(const string& token)
{
    return opmap.find( token )->second;
}
bool Shuntingyard::isOperator( const string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}
//right or left
bool Shuntingyard::isAssociative( const string& token, const int& type)        
{
    return tokenToPair(token).second == type;
}

int Shuntingyard::cmpPrecedence( const string& token1, const string& token2 )        
{            
    return tokenToPair(token1).first - tokenToPair(token2).first;        
}

//---------------------------------------infixToRPN--------------------------------------------------------

// Convert infix expression format into reverse Polish notation

// While there are tokens to be read

//    If token is an operator
//          while token has precedence less than that of top from stack
//                 pop top off the stack, onto the output queue 
//          push o1 onto the stack

//    If the token is a left bracket '('
//          Push token to top of the stack

//    If token is a right bracket ')'
//          Until the token at the top of the stack is a left parenthesis,
//          pop operators off the stack onto the output queue.

//    If the token is a number, then add it to the output queue.

//    While there are still operator tokens in the stack
//          Pop the operator onto the output queue

bool Shuntingyard::infixToRPN( const std::vector<std::string>& inputTokens, 
                 std::vector<std::string>& strArray )
{     
    std::list<std::string> out;
    std::stack<std::string> stack;
    size_t size = inputTokens.size();


    for ( size_t i = 0; i < size; i++ )        
    {      
        const std::string token = inputTokens[ i ];      

        if ( isOperator( token ) )  
        {                    
            const std::string o1 = token;

            if ( !stack.empty() )
            {    
                std::string o2 = stack.top();

                while ( isOperator( o2 ) &&
                        ( ( isAssociative( o1, LEFT_ASSOC ) &&  cmpPrecedence( o1, o2 ) == 0 ) ||    
                        ( cmpPrecedence( o1, o2 ) < 0 ) ) )
                {
                    stack.pop();
                    out.push_back( o2 );

                    if ( !stack.empty() )
                        o2 = stack.top();
                    else
                        break;
                }
            }    
            stack.push( o1 );
        }        
        else if ( token == "(" )
        {
            stack.push( token );
        }        
        else if ( token == ")" )
        {
            std::string topToken  = stack.top();  

            while ( topToken != "(" )        
            {                        
                out.push_back(topToken );        
                stack.pop();    

                if ( stack.empty() ) return false;;//breck
                topToken = stack.top();  
            }
            if ( !stack.empty() ) stack.pop(); //remove '('
            /*
            if ( topToken != "(" )    
            {                        
                return false;    
            }*/
        }
        else
        {
            out.push_back( token );
        }
    
    }

    while ( !stack.empty() )        
    {      
        const std::string stackToken = stack.top();    

        if ( isParenthesis( stackToken )   )  
        {    
            return false;
        }

        out.push_back( stackToken );
        stack.pop();
    }

    strArray.assign( out.begin(), out.end() );  

    return true;
}        

//---------------------------------------calculate--------------------------------------------------------
// If the token is a value push it onto the stack

// Token is an operator: pop top two entries

double Shuntingyard::calculate( const std::string& expression)
{        
    std::vector<std::string> tokens = getExpressionTokens(expression );  
    std::vector<std::string> rpn; 
    if(!infixToRPN( tokens, rpn )) return 0.0;
    tokens = rpn;
    std::stack<std::string> st;       
    size_t size = tokens.size();
    //double result =  0.0;  
    for ( size_t i = 0; i < size; ++i )
    {       
        const std::string token = tokens[ i ];

        if ( !isOperator(token) )
        {        
            st.push(token);
        }        
        else        
        {  
            double result =  0.0;  
            
            const std::string val2 = st.top();      
            st.pop();      
            const double d2 = strtod( val2.c_str(), NULL );        

            if ( !st.empty() )  
            {  
                const std::string val1 = st.top();      
                st.pop();      
                const double d1 = strtod( val1.c_str(), NULL );     

                result = token == "+" ? d1 + d2 :
                         token == "-" ? d1 - d2 :
                         token == "*" ? d1 * d2 : d1 / d2;
            }  
            else  
            {  
                if ( token == "-" )  
                    result = d2 * -1;  
                else   
                    result = d2;  
            }  
            std::ostringstream s;
            s << result;
            st.push( s.str() );
        }
    }
    return strtod( st.top().c_str(), NULL );
}

//---------------------------------------getExpressionTokens-------------------------------------------------

std::vector<std::string> Shuntingyard::getExpressionTokens( const std::string& expression )  
{  
    std::vector<std::string> tokens;
    std::string str = "";
    std::size_t size = expression.length();

    for ( std::size_t i = 0; i < size; ++i )
    {    
        const std::string token( 1, expression[ i ] );

        if ( isOperator( token ) || isParenthesis( token ) )    
        {
            if ( !str.empty() ) //before that numbers appeared
            {
               tokens.push_back( str ) ;
            }
            str = "";           //before that operators or parenthesis appeared
            tokens.push_back( token );
        }    
        else if(token == " ")
        {
            tokens.push_back( str ); 
            str = "";
        }
        else
        {
            str.append( token ); //part of the same number
        }
    }        

    return tokens;  
}

//------------------------------------------------------------------------------------------------------


/*
int main()        
{       
    std::string s = "-4.2*(3/4)-(5+6)";          

    //Print<char, s_iter>( "Input expression:", s.begin(), s.end(), "" );                

    // Tokenize input expression        
    std::vector<std::string> tokens = getExpressionTokens( s );  
    //std::cout << tokens.size()<<std::endl;
    //Print<std::string, cv_iter>( "getExpressionTokens:", tokens.begin(), tokens.end(), "" );

    // Evaluate feasible expressions  
    std::vector<std::string> rpn;        
    if ( infixToRPN( tokens, tokens.size(), rpn ) )      
    {      
        double d = RPNtoDouble( rpn );      
        //Print<std::string, cv_iter>( "RPN tokens:  ", rpn.begin(), rpn.end(), " " );

        std::cout << "Result = " << d << std::endl;      
    }

std::string s = "-4.2*(3/4)-(5+6)"; 
std::vector<std::string> tokens = getExpressionTokens( s );  
std::vector<std::string> rpn; 
infixToRPN( tokens, tokens.size(), rpn )       
double d = RPNtoDouble( rpn );   
std::cout << "Result = " << d << std::endl;



    else      
    {      
        std::cout << "Mis-match in parentheses" << std::endl;      
    }         

    return 0;        
}  */