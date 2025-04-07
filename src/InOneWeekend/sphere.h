#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include <algorithm>
#include <cmath>

class sphere : public hittable {
public:
    // "size" es la longitud de cada lado del cubo.
    sphere(const point3& center, double size, shared_ptr<material> mat)
        : center(center), size(size), mat(mat) {
        half = size * 0.5;
        box_min = center - vec3(half, half, half);
        box_max = center + vec3(half, half, half);
    }

    virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        double tmin = ray_t.min;
        double tmax = ray_t.max;

        // Intersección con el AABB del cubo.
        for (int a = 0; a < 3; a++) {
            double invD = 1.0 / r.direction()[a];
            double t0 = (box_min[a] - r.origin()[a]) * invD;
            double t1 = (box_max[a] - r.origin()[a]) * invD;
            if (invD < 0.0) std::swap(t0, t1);
            tmin = std::max(tmin, t0);
            tmax = std::min(tmax, t1);
            if (tmax <= tmin)
                return false;
        }

        rec.t = tmin;
        rec.p = r.at(rec.t);
        rec.mat = mat;

        // Calcular la normal de la cara golpeada:
        // Se determina cuál de las diferencias (en valor absoluto) es mayor.
        double dx = std::fabs(rec.p.x() - center.x());
        double dy = std::fabs(rec.p.y() - center.y());
        double dz = std::fabs(rec.p.z() - center.z());
        vec3 outward_normal;
        if (dx >= dy && dx >= dz) {
            outward_normal = (rec.p.x() > center.x()) ? vec3(1, 0, 0) : vec3(-1, 0, 0);
        }
        else if (dy >= dx && dy >= dz) {
            outward_normal = (rec.p.y() > center.y()) ? vec3(0, 1, 0) : vec3(0, -1, 0);
        }
        else {
            outward_normal = (rec.p.z() > center.z()) ? vec3(0, 0, 1) : vec3(0, 0, -1);
        }
        rec.set_face_normal(r, outward_normal);
        return true;
    }

private:
    point3 center;
    double size;
    double half;
    point3 box_min;
    point3 box_max;
    shared_ptr<material> mat;
};

#endif
