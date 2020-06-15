import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

import QtQuick.Scene3D 2.0

import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick 2.1

ApplicationWindow
{
    visible: true
    width: 820
    height: 595
    title: qsTr("3D model visualization")
    Entity {
        components: [
            SpotLight {
                //localDirection: Qt.vector3d(1000, 1000.0, 1000.0)
                color: "white"//"#9cdaef"
                intensity: 1500
            }
        ]
    }
    Scene3D
    {
        anchors.fill: parent
        aspects: ["input", "logic"]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
        Entity
        {
            id: sceneRoot

            Camera
            {
                id: camera
                //projectionType: CameraLens.PerspectiveProjection
                 //               fieldOfView: 30
                //                aspectRatio: 16/9
                //                nearPlane : 0.1
                farPlane : 1000.0
                //                position: Qt.vector3d( 300.0, 300.0, 400 )
                //                viewCenter: Qt.vector3d( 0.0, 0.0, 1.0 )
                //                upVector: Qt.vector3d( 0.0, 0.0, 1)
                //                 upVector: Qt.vector3d( 0.0, 0.0, 500)
                position: Qt.vector3d( 0.0, 250.0, 500 )
                viewCenter: Qt.vector3d( 50.0, 50.0, 50.0 )
                //upVector: Qt.vector3d( 0.0, 0.0, 1)
                //viewVector: Qt.vector3d(400.0, 100.0, 100.0)
                //projectionMatrix: Qt.matrix4x4(0.760244597,0.5,0,0,-0.5,0.760244597,0,0,0,0,1,0,0,0,0,1)
            }
            OrbitCameraController
            {
                camera: camera
                linearSpeed: 400
                lookSpeed: 400
            }

            components: [
                RenderSettings
                {
                    activeFrameGraph: ForwardRenderer
                    {
                        clearColor: Qt.rgba(0, 0.5, 1, 1)
                        camera: camera
                    }
                },
                InputSettings
                {},
                Transform {
                    translation: Qt.vector3d(0.0, 250.0, 500.0)
                }
            ]
            Entity
            {
                id: monkeyEntity
                components: [
                    SceneLoader
                    {
                        id: sceneLoader
                        //source : "qrc:/obrocony2.fbx"
                        //source: "qrc:/blendfnx.fbx"
                        source: "qrc:/model/blender3.fbx"
                    },
                    Transform {
                        id: spotLightTransform
                        translation: Qt.vector3d(0.0, 5.0, 0.0)
                        rotationY: 0.0

                        SequentialAnimation {
                            loops: Animation.Infinite
                            running: true

                            NumberAnimation {
                                target: spotLightTransform
                                property: "rotationY"
                                from: 0; to: 360
                                duration: 15000
                                easing.type: Easing.InOutQuad
                            }
                            PauseAnimation { duration: 2500 }
                            NumberAnimation {
                                target: spotLightTransform
                                property: "rotationY"
                                from: 360; to: 0
                                duration: 15000

                                easing.type: Easing.InOutQuad
                            }
                        }
                    }

                ]
            }

        }

    }
}
