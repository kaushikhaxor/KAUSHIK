#define V2 ImVec2
void FX(ImDrawList* d, V2 a, V2 b, V2 sz, ImVec4, float t0)
{
    for (float t = t0; t < t0 + 1.0f; t += 1.0f / 100.0f)
    {
        V2 cp0(a.x, b.y);
        V2 cp1(b);
        float ts = t - t0;
        cp0.x += (0.4f + sin(t) * 0.3f) * sz.x;
        cp0.y -= (0.5f + cos(ts * ts) * 0.4f) * sz.y;
        cp1.x -= (0.4f + cos(t) * 0.4f) * sz.x;
        cp1.y -= (0.5f + sin(ts * t) * 0.3f) * sz.y;
        d->AddBezierCurve(V2(a.x, b.y), cp0, cp1, b, IM_COL32(100 + ts*150, 255 - ts*150, 60, ts * 200), 5.0f);
    }
}

cr - kaushik