external segfault_call : unit -> unit = "caml_segfault_call" 

let () =
  let open Alcotest in
  let call_seg () = 
    try
      segfault_call ();
      fail "Should segfault"
    with 
    | SegFault _ ->
      (check pass) "Exception during nullptr dereference should happen" () ()
    | _ -> 
      fail "Should call segfault exception"
  in
  run __FILE__
    [
      ("segfault", [ test_case "nullexcept" `Quick (function _ -> call_seg ())]);
    ]


