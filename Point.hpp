#pragma once

class Point {
    private:
        double m_d_x;
        double m_d_y;
    public:
        Point();
        Point(double x, double y);
        double x(){
            return m_d_x;
        }
        double y(){
            return m_d_y;
        }
        void setX(double x) {
            m_d_x = x;
        }
        void setY(double y) {
            m_d_y = y;
        }
        double distance_to_origin();
        double distance_to_point(Point p);
};