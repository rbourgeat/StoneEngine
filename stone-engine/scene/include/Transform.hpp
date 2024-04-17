// Copyright 2024 Stone-Engine

#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

namespace STN
{

    class Transform2D
    {
    public:
        Transform2D();
        Transform2D(const Transform2D &other);

        virtual ~Transform2D();

        Transform2D &operator=(const Transform2D &other);

        void setPosition(const glm::vec2 &position);
        void setRotation(float rotation);
        void setScale(const glm::vec2 &scale);

        const glm::vec2 &getPosition() const;
        float getRotation() const;
        const glm::vec2 &getScale() const;

        void translate(const glm::vec2 &translation);
        void rotate(float rotation);
        void scale(const glm::vec2 &scale);

        /** Update if needed and return the transform matrix */
        const glm::mat3 &getTransformMatrix();
        /** Return the transform matrix if cached or calculate it */
        glm::mat3 getTransformMatrix() const;

    protected:
        glm::vec2 _position;
        float _rotation;
        glm::vec2 _scale;

        glm::mat3 _transformMatrix;
        bool _transformMatrixDirty;

        void calculateTransformMatrix(glm::mat3& m) const;
    };

    class Transform3D
    {
    public:
        Transform3D();
        Transform3D(const Transform3D &other);

        virtual ~Transform3D();

        Transform3D &operator=(const Transform3D &other);

        void setPosition(const glm::vec3 &position);
        void setRotation(const glm::quat &rotation);
        void setEulerAngles(const glm::vec3 &eulerAngles);
        void setScale(const glm::vec3 &scale);

        const glm::vec3 &getPosition() const;
        const glm::quat &getRotation() const;
        const glm::vec3 getEulerAngles() const;
        const glm::vec3 &getScale() const;

        void translate(const glm::vec3 &translation);
        void rotate(const glm::quat &rotation);
        void rotate(float angle, const glm::vec3 &axis);
        void rotate(const glm::vec3 &eulerAngles);
        void scale(const glm::vec3 &scale);

        /** Update if needed and return the transform matrix */
        const glm::mat4 &getTransformMatrix();
        /** Return the transform matrix if cached or calculate it */
        glm::mat4 getTransformMatrix() const;

    protected:
        glm::vec3 _position;
        glm::quat _rotation;
        glm::vec3 _scale;

        glm::mat4 _transformMatrix;
        bool _transformMatrixDirty;

        void calculateTransformMatrix(glm::mat4& m) const;
    };

} // namespace STN
