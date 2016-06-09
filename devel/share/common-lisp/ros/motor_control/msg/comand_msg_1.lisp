; Auto-generated. Do not edit!


(cl:in-package motor_control-msg)


;//! \htmlinclude comand_msg_1.msg.html

(cl:defclass <comand_msg_1> (roslisp-msg-protocol:ros-message)
  ((motor
    :reader motor
    :initarg :motor
    :type cl:integer
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0))
)

(cl:defclass comand_msg_1 (<comand_msg_1>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <comand_msg_1>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'comand_msg_1)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor_control-msg:<comand_msg_1> is deprecated: use motor_control-msg:comand_msg_1 instead.")))

(cl:ensure-generic-function 'motor-val :lambda-list '(m))
(cl:defmethod motor-val ((m <comand_msg_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor_control-msg:motor-val is deprecated.  Use motor_control-msg:motor instead.")
  (motor m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <comand_msg_1>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor_control-msg:position-val is deprecated.  Use motor_control-msg:position instead.")
  (position m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <comand_msg_1>) ostream)
  "Serializes a message object of type '<comand_msg_1>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'motor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'motor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'motor)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'position)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <comand_msg_1>) istream)
  "Deserializes a message object of type '<comand_msg_1>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'motor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'motor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'motor)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'position) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<comand_msg_1>)))
  "Returns string type for a message object of type '<comand_msg_1>"
  "motor_control/comand_msg_1")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'comand_msg_1)))
  "Returns string type for a message object of type 'comand_msg_1"
  "motor_control/comand_msg_1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<comand_msg_1>)))
  "Returns md5sum for a message object of type '<comand_msg_1>"
  "6af2c4945f1f8a63edc4ddc639177775")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'comand_msg_1)))
  "Returns md5sum for a message object of type 'comand_msg_1"
  "6af2c4945f1f8a63edc4ddc639177775")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<comand_msg_1>)))
  "Returns full string definition for message of type '<comand_msg_1>"
  (cl:format cl:nil "uint32 motor~%int32 position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'comand_msg_1)))
  "Returns full string definition for message of type 'comand_msg_1"
  (cl:format cl:nil "uint32 motor~%int32 position~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <comand_msg_1>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <comand_msg_1>))
  "Converts a ROS message object to a list"
  (cl:list 'comand_msg_1
    (cl:cons ':motor (motor msg))
    (cl:cons ':position (position msg))
))
