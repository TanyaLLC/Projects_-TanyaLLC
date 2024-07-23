/* Name: Tanya Raphael
Date: 02/20/24
Assignment: 4 
Due Date: 02/26.24
About this project: Calculate passer rating of users input. 
Assumptions:  correct user input and it'll run smoothly. 

All work below was performed by Tanya Raphael.  */


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// declare the functions
void welcomeMessage ( ); 
double getPasserRating ( double , double , double , double , double ); 

int main()
{
      int att1, comp1, yds1, td1, itt1 ; 
      int  att2, comp2, yds2, td2, itt2 ;
      double RatepassA; 
      double RatepassB; 
      char loopagain; 
      int paircount = 0; 
       
        // printing menu
        welcomeMessage ();
       
     do { 
      
      cout << fixed << showpoint << setprecision(1);
      
    
      // information for player A 
      cout << " \n Enter single game information for player A: " << endl; 
      cout << " Attempts: " ; 
      cin >> att1; 
      cout << " Completions: " ; 
      cin >> comp1; 
      cout << " Passing Yards: "; 
      cin >> yds1; 
      cout << " Touchdowns: "; 
      cin >> td1; 
      cout << " Interceptions: "; 
      cin >> itt1; 
    
    // calculation for player A
       RatepassA = getPasserRating ( comp1, att1 , yds1, td1, itt1); 
    
    
      // Information for Player B 
       cout << " \n Enter single game information for player B: " << endl; 
      cout << " Attempts: "; 
      cin >> att2; 
      cout << " Completions: "; 
      cin >> comp2; 
      cout << " Passing Yards: "; 
      cin >> yds2; 
      cout << " Touchdowns: " ; 
      cin >> td2; 
      cout << " Interceptions: " ; 
      cin >> itt2; 
      
      RatepassB = getPasserRating (comp2, att2, yds2, td2, itt2); 
      
     cout << fixed << showpoint << setprecision(1);// set passer rating to one decimal. 
     cout << " \n Player A's single game passer rating: " << RatepassA  << endl; // negative pass rating (both)
     cout << " Player B's single game passer rating: " << RatepassB << endl; 

    // who is the better player
    if (RatepassA > RatepassB )
        cout << " Player A was better than Player B by a difference of " << abs(RatepassA - RatepassB) << endl; // negative number?
        else if (RatepassB > RatepassA )
            cout << " Player B was better than Player B by a difference of " << abs(RatepassB - RatepassA) << endl; // negative number? 
        else 
            cout << " Player A and B have the same rating! " << endl;
    // if player has perfect passrate
    if ( RatepassA >= 158.3)
        cout << " \n Player A had a PERFECT passer rating. " << endl; 
    if ( RatepassB >= 158.3)
        cout << " \n Player B had a PERFECT passer rating. " << endl; 
    
    // if they want to compare again
    cout << " \n Would you like to compare another pair of players? (Y or N): "; 
    cin >> loopagain; 
    paircount++; 
  } while (loopagain == 'Y' || loopagain == 'y'); // continues the loop 
  
    if (loopagain == 'N' || loopagain == 'n')
     {   
        if (paircount > 1 )
        cout << " You compared " << paircount++ << " pairs of players." << endl; 
        else
        cout << " You compared 1 pair of players. " << endl; 
     }
    else 
    cout << "Invalid entry. Exiting program..."; 
    
    
    
    
    
    
    
     return 0;
}
//function definition 
void welcomeMessage ( )
{
    cout << " Welcome to the NFL Quarterback Passer Rating Calculator! " << endl; 
    cout << " A perfect passer rating (158.3) requires at least: " << endl; 
    cout << " 77.5% completion percentage" << endl; 
    cout << " 12.5 yards per attempt " << endl; 
    cout << " 11.875% touchdown % per attempt" << endl; 
    cout << " No interceptions" << endl; 
}
double getPasserRating ( double comp , double  att , double yds , double td, double itt)
{
    double a = ((comp/att)- 0.3) * 5;
    double b = ((yds/att)- 3.0) * 0.25;
    double c = (td/ att) * 20 ;
    double d = 2.375 - ((itt/ att) * 25);  // itt = interseptions
    
    if (a > 2.375 )
        a = 2.375; 
    if (b > 2.375)
        b = 2.375; 
    if (c > 2.375)
        c= 2.375;
    if (d > 2.375)
        d = 3.375;
        
    if (a < 0) 
        a = 0; 
    if (b < 0)
        b = 0; 
    if (c < 0)
        c = 0; 
    if (d < 0) 
        d = 0; 
  
    
    double result = ((a+b+c+d)/6)*100;
    return result;  
}










