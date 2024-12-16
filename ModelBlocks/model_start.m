function nP = model_start()
    sim('ModelBlocks.slx');
    nP = nP_model.Data;
end