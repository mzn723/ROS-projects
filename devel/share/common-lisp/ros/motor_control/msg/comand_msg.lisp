; Auto-generated. Do not edit!


(cl:in-package motor_control-msg)


;//! \htmlinclude comand_msg.msg.html

(cl:defclass <comand_msg> (roslisp-msg-protocol:ros-message)
  ((motor
    :reader motor
    :initarg :motor
    :type cl:fixnum
    :initform 0)
   (position
    :reader position
    :initarg :position
    :type cl:integer
    :initform 0)
   (direction
    :reader direction
    :initarg :direction
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass comand_msg (<comand_msg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <comand_msg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'comand_msg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name motor_control-msg:<comand_msg> is deprecated: use motor_control-msg:comand_msg instead.")))

(cl:ensure-generic-function 'motor-val :lambda-list '(m))
(cl:defmethod motor-val ((m <comand_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor_control-msg:motor-val is deprecated.  Use motor_control-msg:motor instead.")
  (motor m))

(cl:ensure-generic-function 'position-val :lambda-list '(m))
(cl:defmethod position-val ((m <comand_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor_control-msg:position-val is deprecated.  Use motor_control-msg:position instead.")
  (position m))

(cl:ensure-generic-function 'direction-val :lambda-list '(m))
(cl:defmethod direction-val ((m <comand_msg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader motor_control-msg:direction-val is deprecated.  Use motor_control-msg:direction instead.")
  (direction m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <comand_msg>) ostream)
  "Serializes a message object of type '<comand_msg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'position)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'direction) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <comand_msg>) istream)
  "Deserializes a message object of type '<comand_msg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'motor)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'position)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'direction) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<comand_msg>)))
  "Returns string type for a message object of type '<comand_msg>"
  "motor_control/comand_msg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'comand_msg)))
  "Returns string type for a message object of type 'comand_msg"
  "motor_control/comand_msg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<comand_msg>)))
  "Returns md5sum for a message object of type '<comand_msg>"
  "a0046743715cfd63f29b50134bc02d4f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'comand_msg)))
  "Returns md5sum for a message object of type 'comand_msg"
  "a0046743715cfd63f29b50134bc02d4f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<comand_msg>)))
  "Returns full string definition for message of type '<comand_msg>"
  (cl:format cl:nil "uint8 motor~%uint32 position~%bool direction~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'comand_msg)))
  "Returns full string definition for message of type 'comand_msg"
  (cl:format cl:nil "uint8 motor~%uint32 position~%bool direction~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <comand_msg>))
  (cl:+ 0
     1
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <comand_msg>))
  "Converts a ROS message object to a list"
  (cl:list 'comand_msg
    (cl:cons ':motor (motor msg))
    (cl:cons ':position (position msg))
    (cl:cons ':direction (direction msg))
))
