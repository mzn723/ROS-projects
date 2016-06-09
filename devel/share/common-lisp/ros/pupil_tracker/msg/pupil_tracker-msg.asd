
(cl:in-package :asdf)

(defsystem "pupil_tracker-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "gaze_position" :depends-on ("_package_gaze_position"))
    (:file "_package_gaze_position" :depends-on ("_package"))
  ))