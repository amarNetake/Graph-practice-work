/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    vector<vector<int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
    
    void clean(Robot& robot,int x,int y,int curDirection,unordered_map<string,bool>& ma)
    {
        robot.clean();
        string curr=to_string(x)+"$"+to_string(y);
        ma[curr]=true;
        
        for (int nDirection = curDirection; nDirection < curDirection + 4; nDirection++) 
        {
            int nx = directions[nDirection % 4][0] + x;
            int ny = directions[nDirection % 4][1] + y;
            string next=to_string(nx)+"$"+to_string(ny);
            if (ma.find(next)==ma.end() && robot.move()) 
            {
                clean(robot, nx, ny, nDirection % 4, ma);
            }
            // Changed orientation.
            robot.turnRight();
        }
        
        // Moves backward one step while maintaining the orientation.
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void cleanRoom(Robot& robot)   //Driver function
    {
        unordered_map<string,bool> ma;
        clean(robot,0,0,0,ma);
    }
};