
(cl:in-package :asdf)

(defsystem "motor_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "jointState" :depends-on ("_package_jointState"))
    (:file "_package_jointState" :depends-on ("_package"))
    (:file "comand_msg" :depends-on ("_package_comand_msg"))
    (:file "_package_comand_msg" :depends-on ("_package"))
    (:file "comand_msg_1" :depends-on ("_package_comand_msg_1"))
    (:file "_package_comand_msg_1" :depends-on ("_package"))
  ))