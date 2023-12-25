#include <iostream>
#include <string>

/*
+-------------------------+       +---------------------+
|    FitnessTracker       |       |      Activity       |
+-------------------------+       +---------------------+
| -user_type: String      |       | -type: String       |
| -username: String       |       | -duration: int      |
| -user_id: int           |       | -calories_burned: int|
| -activities: List<Activity>|      | -heart_rate: int    |
+-------------------------+       | -date: String       |
| +record_activity(...)   |       +---------------------+
| +calculate_calories(...)|
| +record_heart_rate(...) |
| +generate_report()      |
| +set_goals(...)          |
| +track_progress()        |
+-------------------------+

*/

class Activity
{

};

class FitnessTracker{};