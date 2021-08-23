#pragma once

class Dot;
class Circle;
class Line;

namespace Collisions
{
    bool IsIntersect(const Dot& dot, const Circle& circle);
    bool IsIntersect(const Circle& circle, const Dot& dot);
    bool IsIntersect(const Circle& circle, double x, double y);

    bool IsIntersect(const Line& line, const Circle& circle);
    bool IsIntersect(const Circle& circle, const Line& line);
}